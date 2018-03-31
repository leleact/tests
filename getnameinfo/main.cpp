#include <cstdio>
#include <cstring>
#include <cerrno>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    if ( argc != 2 ) {
        printf("please use %s IP\n", argv[0]);
        return -1;
    }
    struct sockaddr_in sock;
    sock.sin_family = AF_INET;
    sock.sin_port = 22;
    inet_pton(AF_INET, argv[1], &(sock.sin_addr));

    char host[NI_MAXHOST] = { 0 };
    size_t host_size = sizeof(host);
    char serv[NI_MAXSERV] = { 0 };
    size_t serv_size = sizeof(serv);

    int ret = getnameinfo((struct sockaddr *)&sock, sizeof(sock), host, host_size, serv, serv_size, NI_NAMEREQD);
    if ( ret != 0) {
        printf("An error ocured errno[%d][%s]\n", errno, strerror(errno));
        return -1;
    }

    printf("host[%s]\n", host);
    printf("serv[%s]\n", serv);

    return 0;
}
