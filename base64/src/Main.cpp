#include <iostream>
#include <cstring>
#include "base64.h"
int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Argument error!"  << std::endl;
        return -1;
    }

    char *type = argv[1];
    char *in = argv[2];
    std::string str = in;
    if (strncmp("encode", type, 5) == 0) {
        std::cout << base64_encode(reinterpret_cast<const unsigned char *>(str.c_str()), static_cast<int>(str.size())) << std::endl;
    } else if (strncmp("decode", type, 5) == 0) {
        std::cout << base64_decode(str) << std::endl; 
    }
    return 0;
}
