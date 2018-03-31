#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "please use : lele_test_http <url>" << std::endl;
        return -1;
    }
    int serv_port = 80;
    int ret = 0;
    int sock_fd;
    std::size_t const buff_size = 1024;
    //  std::string serv_des = "www.qq.com";
    std::string serv_des = argv[1];
    struct sockaddr_in serv_addr;
    struct hostent *phost = nullptr;

    phost = gethostbyname(serv_des.c_str());
    if (phost == nullptr) {
        std::cerr << "gethostbyname error" << std::endl;
        return -1;
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if ( sock_fd < 0) {
        std::cerr << "socket create error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(serv_port);
    std::memcpy(&serv_addr.sin_addr, phost->h_addr_list[0], phost->h_length);

    ret = connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
    if ( ret < 0) {
        std::cerr << "connect error" << std::endl;
        return -1;
    }

    char strbuff[buff_size];
    std::sprintf(strbuff, "GET / HTTP/1.1\n""Host:%s""\n\n", argv[1]);
    std::size_t n = write(sock_fd, strbuff, strlen(strbuff));
    if (!n) {
        std::cerr << "write error" << std::endl;
        return -1;
    }

    while(read(sock_fd, strbuff, 1024)) {
        std::cout.flush();
        std::cout << strbuff ;
    }

    close(sock_fd);

    return 0;
}
