#include <iostream>
#include <cstring>

struct server {
    char ip[20];
    int port;
};

int main() {
    struct server m_lpsr[256];

    std::cout << sizeof(m_lpsr) << std::endl;
    std::cout << sizeof(struct server) << std::endl;


    return 0;
}
