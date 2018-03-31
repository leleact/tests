
#ifndef _VARLIB_SOCKET_HPP
#define _VARLIB_SOCKET_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>

namespace varlib {

class socket_exception : public std::exception {

public:
    socket_exception(const char *file, int line, const char *msg = "") noexcept;
    const char *what() const noexcept override;

private:
    std::string m_file;
    int m_line;
    int m_errno;
    std::string m_message;
    std::string m_what_message;

    void build_what_message() noexcept;
};

// Only IPv4 UDP supported

class socket {
public:
    socket() : m_addr_(""), m_port(-1), m_fd(create_fd()) {}

    socket(const std::string addr, int port, bool bind = true) :
        m_addr_(addr), m_port(port), m_fd(create_fd()) {}

    virtual ~socket();

    void bind();

    void bind(int port);

    void bind(const std::string& , int port);

    void connect();

    void connect(const std::string&, int port);

    ssize_t sendto(const std::string& msg, const std::string& addr, const int port, int flag = 0);

    ssize_t recvfrom(std::string& data, std::string& remote_addr, int& remote_port, int flag = 0);

protected:
    void close_fd();

    int create_fd();

private:
    std::string m_addr_;
    int m_port;
    int m_fd;

    socket(const socket&) = delete;
    socket& operator=(const socket&) = delete;
};

}
#endif
