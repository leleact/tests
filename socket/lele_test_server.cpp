#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdio.h>
#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h> /* inet_pton */
#include <errno.h>

void setnonblock(int , int);
int main(int argc, char **argv) {
	/**
	 * argv[0] 程序名称
	 * argv[1] 监听端口
	 */
	if (2 != argc) {
		std::cout << "please using <server> <port>" << std::endl;
		return -1;
	}

	unsigned short usPort = atoi(argv[1]);


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
	nRet = inet_pton(AF_INET, "0.0.0.0", &stSockAddr.sin_addr);
	if (nRet == -1) {
		std::cerr << "inet_pton() error" << std::endl;
		return -1;
	} 

	// 绑定连接
	nRet = bind(nSocket, (sockaddr *)&stSockAddr, sizeof(stSockAddr));
	if (-1 == nRet) {
		std::cerr << "bind error" << std::endl;
		return -1;
	}

	// 监听端口
	nRet = listen(nSocket, 5);
	if (-1 == nRet) {
		std::cerr << "listen error" << std::endl;
		return -1;
	}

	// 接收连接
	socklen_t nSocklen = sizeof(struct sockaddr);
	int nNewSocketFd = accept(nSocket, (struct sockaddr *)(&stSockAddr), &nSocklen);
	if (-1 == nRet) {
		std::cerr << "accept error" << std::endl;
		return -1;
	}
	printf("accept ... \n");
	setnonblock(nNewSocketFd, O_NONBLOCK);
	int index = 0;
	const int nMaxBuffSize = 9;
	char czBuff[nMaxBuffSize] = {0};
	while(1)
	{
		sleep(10);
		/*
		nRead = read(nNewSocketFd, czBuff, sizeof(czBuff));
		if (nRead == (size_t)(-1))
		{
			if (errno == EINTR)
			{
				printf("%s:%d read has been interrupt\n", __FILE__, __LINE__ );	
				continue;	
			}
			else if (errno == EAGAIN)
			{
				printf("%s:%d none read data\n", __FILE__, __LINE__);	
				continue;
			}
			printf("%s:%d read Error[%d] Errmsg[%s]\n", __FILE__, __LINE__, errno, strerror(errno));	
			return -1;
		}
		else if (nRead == 0)
		{
			printf("%s:%d socket has been closed normally!\n", __FILE__, __LINE__);	
			break;
		}
		printf("read[%s][%ld][%d]\n", czBuff, nRead, errno);
		write(nFd, czBuff, nRead); 
		write(nNewSocketFd, czBuff, nRead); 
		printf("%s:%d errno[%d]\n", __FILE__, __LINE__, errno);
		*/
		size_t nRecv = recv(nNewSocketFd, czBuff, sizeof(czBuff), 0);
		if (nRecv == 0)
		{
			break;	
		}
		if (nRecv == size_t(-1))
		{
			if (errno == 11)
			{
				printf("%s:%d err[%d][%s]\n", __FILE__, __LINE__, errno, strerror(errno));
				continue;
			}
			printf("%s:%d err[%d][%s]\n", __FILE__, __LINE__, errno, strerror(errno));
			break;
		}
		char filename[256] = {'\0'};
		sprintf(filename, "%d.log", index++);
		int nFd = open(filename, O_WRONLY|O_CREAT, 0644);
		if (nFd <= 0) {
			std::cerr << "open error" << std::endl;
			return -1;
		}	
		write(nFd, czBuff, nRecv);
		close(nFd);
	}
	close(nNewSocketFd);
	close(nSocket);
	return 0;
}

void setnonblock(int fd, int flag)
{
	int val ;
	if ((val = fcntl(fd, F_GETFL,0)) < 0)
	{
		perror("fcntl error");	
		exit(1);
	}

	val |= flag;
	
	if (fcntl(fd, F_SETFL, val) < 0)
	{
		perror("fcntl F_SETFL error");	
		exit(1);
	}
}
