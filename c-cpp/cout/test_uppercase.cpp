// http://stackoverflow.com/questions/28795137/how-to-print-addresses-hex-values-in-upper-case-in-c
#include <iostream>
#include <sstream>
#include <iomanip>
int main(int argc, char *argv[]) {
    int i = 10;
    std::cout << "0x" << std::hex << std::uppercase << reinterpret_cast<uintptr_t>(&i) << std::endl;
    std::cout << "0x" << std::hex << std::uppercase << reinterpret_cast<unsigned long>(&i) << std::endl;
    return 0;
}
