#include <iostream>

template <typename T>
class base {
public:
    void impl () {
        static_cast<T *>(this)->impl();
    }
};

class derive1 : public base<derive1> {
public:
    void impl() const {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

class derive2 : public base<derive2> {
public:
    void impl() const {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main() {
    base<derive1> *b1 = new derive1();
    base<derive2> *b2 = new derive2();

    b1->impl();
    b2->impl();

    delete b1;
    delete b2;
}
