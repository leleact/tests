#include <iostream>
#include <type_traits>
#include <iomanip>

struct A {};
struct B : public A {};
struct C {};
struct D : public B {};

int main(int argc, char *argv[]) {

    std::cout << "A2B:" << std::boolalpha << std::is_base_of<A, B>::value << std::endl;
    std::cout << "B2A:" << std::boolalpha << std::is_base_of<B, A>::value << std::endl;
    std::cout << "A2A:" << std::boolalpha << std::is_base_of<A, A>::value << std::endl;
    std::cout << "D2A:" << std::boolalpha << std::is_base_of<D, A>::value << std::endl;
    std::cout << "D2B:" << std::boolalpha << std::is_base_of<D, B>::value << std::endl;

    return 0;
}
