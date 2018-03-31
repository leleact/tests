#include <iostream>
#include "Singleton.hpp"

class A {
    public:
        void show() {
            std::cout << "xx" << std::endl; 
        }
};

int main() {
    Singleton<A>::getInstance().type_value.show();
    return 0;
}
