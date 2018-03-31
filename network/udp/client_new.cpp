
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "socket.hpp"

int main(int argc, char **argv) {

    if (3 != argc && 2 != argc) {
        std::cout << "please using <client> <IPaddr> <port>" << std::endl;
        return -1;
    }

    std::string strIPAddr ;
    unsigned short usPort ;

    if (3 == argc) {
        strIPAddr = argv[1]; 
        usPort = atoi(argv[2]);
    } else if (2 == argc) {
        strIPAddr = "0.0.0.0"; 
        usPort = atoi(argv[1]);
    }

    // 准备socket
    varlib::socket sock;

    std::string str;
    std::cout << "enter some word:";
    std::cin >> str;

    while(1) {
        ssize_t n = sock.sendto(str, strIPAddr, usPort);
        if (n == -1) {
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
                << " sendto error, errno[" << errno  << "][" << strerror(errno) << "]" << std::endl;
            continue;
        }
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " send [" << n << "] bytes [" << str << "] to [" << strIPAddr << ":" << usPort<< "]" << std::endl;

        std::string data;
        std::string remote_addr;
        int remote_port;
        n = sock.recvfrom(data, remote_addr, remote_port);
        if (-1 == n) {
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
                << " recvfrom error, errno[" << errno  << "][" << strerror(errno) << "]" << std::endl;

        }
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " recv [" << n << "] bytes [" << data << "] from [" << remote_addr << ":"
            << remote_port << "][" << str << "]" << std::endl;
    }
    return 0;
}
