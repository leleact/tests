#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h> /* struct sockaddr_in   */
#include <arpa/inet.h>  /* inet_pton, inet_ntop */
#include <errno.h>
#include <stdlib.h>

using namespace std;

int setnonblock(int , int);
void print_use(int argc, char *argv[]);
int getaddressinfo(struct sockaddr_in *src_addr, char *pIp, socklen_t iplen, int *pPort);

int main(int argc, char **argv) {
    if (2 != argc) {
        print_use(argc, argv);
        return -1;
    }

    int nPort = atoi(argv[1]);

    // 准备socket
    int udp_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_fd <= 0) {
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " errno:[" << errno << "][" << strerror(errno) << "]" << std::endl;
        return -1;
    }

    // 填充IP地址和端口
    struct sockaddr_in stSockAddr;
    memset(&stSockAddr, 0x00, sizeof(stSockAddr));
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(nPort);
    if( 1 !=  inet_pton(AF_INET, "0.0.0.0", &stSockAddr.sin_addr) ) {
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " inet_pton error, errno[" << errno << "][" << strerror(errno) << "]" << std::endl;
        return -1;
    }

    // 绑定端口
    if(0 != bind(udp_fd, (struct sockaddr *)&stSockAddr, sizeof(stSockAddr)) ) {
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " bind error, errno:[" << errno << "][" << strerror(errno) << "]" << std::endl;
        return -1;
    }

    struct sockaddr_in src_addr;
    socklen_t addrlen = sizeof(src_addr);
    while(1) {
        char buf[10 + 1] = { 0 };
        char ipaddr[16 + 1] = { 0 };
        int nport = 0;
        ssize_t n = recvfrom(udp_fd, buf, 10, 0, (struct sockaddr *)&src_addr, &addrlen);
        if (n == -1) {
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
                << " recvfrom error, errno:[" << errno << "][" << strerror(errno) << "]" << std::endl;
        }
        getaddressinfo(&src_addr, ipaddr, 16, &nport);
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " recv [" << n << "] bytes [" << buf << "] from [" << ipaddr << ":" << nport << "][" << addrlen << "]" << std::endl;
        n = sendto(udp_fd, buf, n, 0, (struct sockaddr *)&src_addr, addrlen);
        if (n == -1) {
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
                << " sendto error, errno[" << errno << "][" << strerror(errno) << "]" << std::endl;
        }
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " send [" << n << "] bytes [" << buf << "] to [" << ipaddr << ":" << nport << "]" << std::endl;
    }

    close(udp_fd);
    return 0;
}

int setnonblock(int fd, int flag) {
    int val ;
    if ((val = fcntl(fd, F_GETFL,0)) < 0) {
        perror("fcntl error");
        return -1;
    }

    val |= flag;

    if (fcntl(fd, F_SETFL, val) < 0) {
        perror("fcntl F_SETFL error");
        return -1;
    }
}

void print_use(int argc, char *argv[]) {
    std::cout << "Use " << argv[0] << " [listen-port]" << std::endl;
}

int getaddressinfo(struct sockaddr_in *src_addr, char *pIp, socklen_t iplen, int *pPort) {
    const char *pAddr = inet_ntop(AF_INET, &(src_addr->sin_addr), pIp, iplen);
    if (pAddr == NULL) {
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " inet_ntop error, errno:[" << errno << "][" << strerror(errno) << "]" << std::endl;
        return -1;
    }
    *pPort = ntohs(src_addr->sin_port);
    return 0;
}
