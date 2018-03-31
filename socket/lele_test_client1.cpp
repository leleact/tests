#define VAR_GCC_
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <string.h>
#ifdef VAR_GCC_
#include <unistd.h>
#include <fcntl.h>
#endif
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h> /* inet_pton */
#include <errno.h>

int main(int argc, char **argv) {
    /**
     * argv[0] 程序名称
     * argv[1] 发往IP地址
     * argv[2] 发往端口
     */
    if (3 != argc) {
        std::cout << "please using <client> <IPaddr> <port>" << std::endl;
        return -1;
    }

    std::string strIPAddr = argv[1];
    unsigned short usPort = atoi(argv[2]);

    // 准备socket
    int nSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == nSocket) {
        std::cerr << "socket() error" << std::endl;
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

    // 建立连接
    nRet = connect(nSocket, (sockaddr *)&stSockAddr, sizeof(stSockAddr));
    if (-1 == nRet) {
        std::cerr << "connect error" << std::endl;
        return -1;
    }

	getchar();
	char strBuff[1024] = {0};
	while(1) {
		sleep(1);
		size_t nSend = send(nSocket, "1111", 5, 0);
		if (nSend == (size_t)-1) {
			printf("%s:%d err[%d][%s]\n", __FILE__, __LINE__, errno, strerror(errno));
			continue;	
		}

		memset(strBuff, 0x00, sizeof(strBuff));
		std::size_t iRead = recv(nSocket, strBuff, sizeof(strBuff), 0);
		if (iRead == (size_t)-1) {
			printf("[%s:%d] err[%d][%s]\n", __FILE__, __LINE__, errno, strerror(errno));	
			close(nSocket);
		}
		
		if (iRead == 0)	{
			// peer has performed orderly shutdown;
			printf("[%s:%d] err[%d][%s]\n", __FILE__, __LINE__, errno, strerror(errno));	
			close(nSocket);
		}
	}
    close(nSocket);
    return 0;
}
