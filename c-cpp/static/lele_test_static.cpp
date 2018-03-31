#include <iostream>

namespace ns_20170714 {
    int main(int, char **);
}

int main(int argc, char *argv[]) {
    return ns_20170714::main(argc, argv);
}

namespace ns_20170714 {

class A {
    friend std::ostream& operator<<(std::ostream& os, const A& a) {
        os << &a;
        return os;
    }
public:
    static A& getA() { return a; }
private:
    static A a;
    A() {}
};

A A::a;

int main(int , char *[]) {
    std::cout << A::getA() << std::endl;
    //std::cout << A::a << std::endl;  // error [ 'a' is a private member of 'ns_20170714::A' ]
    return 0;
}

}


namespace ns_unknow {

struct A {
        static int i ;
};

int A::i = 100;

int main(int , char*[]) {
    std::cout << A::i << std::endl;
    return 0;
}

}
