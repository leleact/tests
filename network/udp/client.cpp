#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h> /* inet_pton */
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (3 != argc) {
        std::cout << "please using <client> <IPaddr> <port>" << std::endl;
        return -1;
    }

    std::string strIPAddr = argv[1];
    unsigned short usPort = atoi(argv[2]);

    // 准备socket
    int nSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (-1 == nSocket) {
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " errno:" << errno << " ," << strerror(errno) << std::endl;
        return -1;
    }

    // 填充IP地址和端口
    struct sockaddr_in stSockAddr;
    memset(&stSockAddr, 0x00, sizeof(stSockAddr));
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(usPort);
    int nRet = 0;
    nRet = inet_pton(AF_INET, strIPAddr.c_str(), &stSockAddr.sin_addr);
    if (nRet == -1) {
        std::cerr << "inet_pton() error" << std::endl;
        return -1;
    }

    std::string str;
    while(1) {
        std::cout << "enter some word:";
        std::cin >> str;
        ssize_t n = sendto(nSocket, str.c_str(), str.length(), 0, (struct sockaddr *)&stSockAddr, sizeof(stSockAddr));
        if (n == -1) {
            std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
                << " sendto error, errno[" << errno  << "][" << strerror(errno) << "]" << std::endl;
            continue;
        }
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " send " << n << " bytes to [" << strIPAddr << ":" << usPort<< "][" << str << "]" << std::endl;
        char buf[10] = { 0 };
        struct sockaddr_in remoteaddr;
        socklen_t socklen;
        n = recvfrom(nSocket, buf, 10, 0, (struct sockaddr *)&remoteaddr, &socklen);
        std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __PRETTY_FUNCTION__
            << " recv " << n << " bytes from [" << inet_ntoa(remoteaddr.sin_addr) << ":"
            << ntohs(remoteaddr.sin_port) << "][" << str << "]" << std::endl;
    }
    close(nSocket);
    return 0;
}
