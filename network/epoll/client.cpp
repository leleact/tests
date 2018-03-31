#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h> /* inet_pton */
#include <errno.h>
#include "exception.hpp"
#include <stdlib.h>

int main(int argc, char **argv) {
    /**
     * argv[0] 程序名称
     * argv[1] 发往IP地址
     * argv[2] 发往端口
     */
    VARLIB_THROW_COND_MSG(3 != argc, "please using <client> <IPaddr> <port>");

    std::string strIPAddr = argv[1];
    unsigned short usPort = atoi(argv[2]);

    int nSocket = socket(AF_INET, SOCK_STREAM, 0);
    VARLIB_THROW_COND(nSocket < 0)

    struct sockaddr_in stSockAddr;
    memset(&stSockAddr, 0x00, sizeof(stSockAddr));
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(usPort);
    int nRet = 0;
    nRet = inet_pton(AF_INET, strIPAddr.c_str(), &stSockAddr.sin_addr);
    VARLIB_THROW_COND(nRet != 1)

    nRet = connect(nSocket, (sockaddr *)&stSockAddr, sizeof(stSockAddr));
    VARLIB_THROW_COND( nRet < 0)

    while(1) {
        std::string str;
        std::cin >> str;
        size_t send_size = send(nSocket, str.c_str(), str.length(), 0);
        if (send_size == (size_t)-1) {
            printf("%s:%d err[%d][%s]\n", __FILE__, __LINE__, errno, strerror(errno));
            continue;
        }
    }
    return 0;
}
