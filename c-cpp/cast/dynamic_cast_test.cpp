#include <iostream>
#include <cstdio>

struct Base {
    int m_b;
    virtual ~Base() {}
};

struct Derive1 : Base {
    int m_d1;
};

struct Derive2 : Base {
    int m_d2;
    std::string m_str;
};

int main(int argc, char *argv[]) {
    Base* pB = new Derive1();
    printf("%p\n", pB);

    Derive1* pD1 = dynamic_cast<Derive1*>(pB);
    printf("%p\n", pD1);
}
