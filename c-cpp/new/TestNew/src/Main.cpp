#include <iostream>
#include <new>
int main() {
    int *p = new(std::nothrow) int[1000 * 10000000000000];
    std::cerr << "Addr:" << p << std::endl;

    try {
        int *q = new int[100000000000000000];
    } catch (std::bad_alloc &ba) {
        std::cerr << ba.what() << std::endl; 
    }
    return 0;
}
