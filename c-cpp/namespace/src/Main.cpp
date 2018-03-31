#include <iostream>
#include "name1.hpp"
#include "name2.hpp"

using name1::A;
void f();
int main(int argc, char *argv[]) {
    A a;
    f();
    A a1;
    return 0;
}


void f() {
    using name2::A;
    A a;
}
