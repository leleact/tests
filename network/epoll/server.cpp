#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "exception.hpp"

const int nMaxEvent = 10000;

bool set_fd_nonblocking(int fd, bool blocking);

int main() {
    struct epoll_event ev, events[nMaxEvent];
    int epfd = epoll_create(1);
    VARLIB_THROW_COND(epfd < 0);

    struct sockaddr_in clientaddr, serveraddr;
    socklen_t socklen = sizeof(clientaddr);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    VARLIB_THROW_COND(listenfd < 0);

    bool b_ret = set_fd_nonblocking(listenfd, true);
    VARLIB_THROW_COND(!b_ret);

    ev.data.fd = listenfd;
    ev.events = EPOLLIN|EPOLLET;
    int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);
    VARLIB_THROW_COND(ret < 0);

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    VARLIB_THROW_COND(inet_pton(AF_INET, "0.0.0.0", &serveraddr.sin_addr) != 1);
    serveraddr.sin_port = htons(8080);

    ret = bind(listenfd, (sockaddr *)&serveraddr, sizeof(serveraddr));
    VARLIB_THROW_COND(ret < 0);

    ret = listen(listenfd, 5);
    VARLIB_THROW_COND(ret < 0);

    while(1) {
        int nfds = 0;
        nfds = epoll_wait(epfd, events, nMaxEvent, -1);
        std::cout << "nfds[" << nfds << "]" << std::endl;
        for (int i = 0; i < nfds; ++i) {
            if (events[i].data.fd == listenfd) {
                int connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &socklen);
                VARLIB_THROW_COND(connfd < 0);
                set_fd_nonblocking(connfd, true);
                std::cout << "accept a connection from [" << inet_ntoa(clientaddr.sin_addr)
                    << ":" << clientaddr.sin_port << "]" << std::endl;
                ev.data.fd = connfd;
                ev.events = EPOLLIN|EPOLLET;
                std::cout << "add ev addr:" << (long)&ev << std::endl;
                ret = epoll_ctl(epfd, EPOLL_CTL_ADD,connfd,&ev);
                VARLIB_THROW_COND(ret != 0);
            } else if (events[i].events & EPOLLIN) {
                struct sockaddr_in address;
                socklen_t address_len = sizeof(address);
                int ret = getpeername(events[i].data.fd, (struct sockaddr *)&address, &address_len);
                VARLIB_THROW_COND(ret != 0);

                {
                    std::cout << "EPOLLIN ev addr:" << (long)&events[i] << ", ev.fd" << events[i].data.fd << std::endl;
                    char ip[16 + 1] = { 0 };
                    std::cout << "sin_family:[" << address.sin_family << "]\n"
                        << "port:[" << address.sin_port << "]\n"
                        << "ip:[" << inet_ntop(address.sin_family, &address.sin_addr, ip, sizeof(ip)) << "]\n";
                }

                char strBuff[1024] = {'\0'};
                int n = 0;
                int nRecv = 0;
                while((nRecv = recv(events[i].data.fd, strBuff + n, 1024 - n, 0)) > 0) {
                    n = n + nRecv;
                }

                if (nRecv == -1 && errno != EAGAIN) {
                    std::cout << "epoll_ctl_del: " << events[i].data.fd << ",errno: " << errno << ",msg:" << strerror(errno) << std::endl;
                    epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
                    close(events[i].data.fd);
                    events[i].data.fd = -1; // INVALID SOCKET
                    continue;
                }
                if (nRecv == 0) {
                    std::cout << "epoll_ctl_del: " << events[i].data.fd << " closed" <<  std::endl;
                    epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
                    close(events[i].data.fd);
                    events[i].data.fd = -1; // INVALID SOCKET
                    continue;
                }
                std::cout << "strBuff[" << strBuff << "], fd:" << events[i].data.fd << std::endl;
            }
            else if (events[i].events & EPOLLOUT) {
                sleep(3);
                std::cout << "EPOLLOUT" << std::endl;
            }
        }
    }
}

bool set_fd_nonblocking(int fd, bool blocking) {
    if (fd < 0)
        return false;
    int opts;
    opts = fcntl(fd, F_GETFL);
    VARLIB_THROW_COND(opts < 0)

        opts = blocking ? opts | O_NONBLOCK : opts & ~O_NONBLOCK;
    if (fcntl(fd, F_SETFL, opts) < 0) {
       VARLIB_THROW_DEFAULT
    }
    return true;
}
