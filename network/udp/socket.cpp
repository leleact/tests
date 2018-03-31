
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h> /* struct sockaddr_in   */
#include <arpa/inet.h>  /* inet_pton, inet_ntop */
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include "socket.hpp"

namespace varlib {

socket_exception::socket_exception(const char *file, int line, const char *msg) noexcept
    : m_file(file), m_line(line), m_errno(errno), m_message(msg) {
    build_what_message();
}

const char* socket_exception::what() const noexcept {
    return m_what_message.c_str();
}

void socket_exception::build_what_message() noexcept {
    std::ostringstream os;
    os << "(" << m_file << ":" << m_line << ")";
    if (m_errno != 0) {
        os << "[" << m_errno << "][" << strerror(m_errno) << "]";
    }
    os << "[" << m_message << "]";
    m_what_message = os.str();
}

// Only IPv4 supported

socket::~socket() { close_fd(); }

void socket::bind() {
    bind(m_addr_, m_port);
}

void socket::bind(int port) {
    bind("0.0.0.0", port);
}

void socket::bind(const std::string& addr, int port) {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    if (1 != inet_pton(AF_INET, addr.c_str(), &sa.sin_addr) ) {
        throw socket_exception(__FILE__, __LINE__, "inet_pton error");
    }
    sa.sin_port = htons(port);
    int rc = ::bind(m_fd, (struct sockaddr *)&sa, sizeof(sa));
    if (rc != 0) {
        throw varlib::socket_exception(__FILE__, __LINE__, "bind error");
    }
}

ssize_t socket::sendto(const std::string& msg, const std::string& addr, const int port, int flag) {
    if (m_fd < 0) {
        return -1;
    }
    assert(addr.length() != 0);
    assert(port != 0);
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    int rc = inet_pton(AF_INET, addr.c_str(), &sa.sin_addr);
    if (rc != 1) {
        throw socket_exception(__FILE__, __LINE__);
    }
    sa.sin_port = htons(port);
    return ::sendto(m_fd, msg.c_str(), msg.length(), flag, (struct sockaddr *)&sa, sizeof(sa));
}

ssize_t socket::recvfrom(std::string& data, std::string& remote_addr, int& remote_port, int flag) {
    if (m_fd < 0) {
        return -1;
    }
    char buff[ 1024 + 1] = { 0 };
    struct sockaddr_in remote_sockaddr;
    socklen_t remote_len = sizeof(remote_sockaddr);
    ssize_t rc = ::recvfrom(m_fd, buff, 1024, flag, (struct sockaddr *)&remote_sockaddr, &remote_len);
    data.append(buff, rc);

    char addr[16 + 1] = { 0 };
    if (NULL != inet_ntop(AF_INET, &remote_sockaddr.sin_addr, addr, 16 )) {
        remote_addr = addr;
    }
    remote_port = ntohs(remote_sockaddr.sin_port);

    return rc;
}

void socket::close_fd() {
    if (m_fd >= 0) {
        close(m_fd);
    }
}

int socket::create_fd() {
    return ::socket(AF_INET, SOCK_DGRAM, 0);
}

}
