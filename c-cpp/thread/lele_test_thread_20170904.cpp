#include <iostream>
#include <thread>

class Param {
private:
    int a = 1;
    int b = 2;
public:
    void foo() {
        a = 3;
        b = 4;
    }

    int getA() { return a; }
    int getB() { return b; }
};

void t1_fun(Param& p) {
    p.foo();
}

void t2_func(Param& p) {
    int a = p.getA();
    int b = p.getB();
    std::clog << "a=[" << a << "]" << std::endl;
    std::clog << "b=[" << b << "]" << std::endl;
    std::clog << "\n" << std::endl;
}

int run() {
    Param p;
    std::thread t1(t1_fun, std::ref(p));
    std::thread t2(t2_func, std::ref(p));

    t1.join();
    t2.join();
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Argument error, please use \n\t"  << argv[0] << " [times]" << std::endl;
        return -1;
    }

    int times = std::atoi(argv[1]);

    for(int i = 0; i < times; i++) {
        run();
    }

    return 0;
}
