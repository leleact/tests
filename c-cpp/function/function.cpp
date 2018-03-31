#include <iostream>
#include <functional>

#define PF std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__ << "]" << std::endl;

class c {
public:
    void f(int) { PF }
    static void g(int) { PF }
};

class d {
public:
    void f() { PF }
    void f(int) { PF }
};

void f() { PF }
void f(int) { PF }

/**
 *  重载的函数,需要显示转换成函数指针
 */

int main() {

    {
        int i = 100;
        std::function<void (int)> f1 = static_cast<void (*)(int)>(f);
        std::function<void ()>    f2 = static_cast<void(*)()>(f);
        f1(i);
        f2();
    }

    {
        std::function<void(c, int)> f1 = &c::f;
        std::function<void(int)> f2 = &c::g;
        c c1;
        f1( c1, 10 );
        f2(10);
    }

    {
        std::function<void(d)> f1      = static_cast<void(d::*)()>(&d::f);
        std::function<void(d, int)> f2 = static_cast<void (d::*)(int)>(&d::f);
        d d1;
        f1(d1);
        f2(d1, 10);
    }

}
