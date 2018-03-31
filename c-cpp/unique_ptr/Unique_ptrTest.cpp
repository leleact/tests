#include <iostream>
#include <memory>

#define PF std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" \
    << __PRETTY_FUNCTION__ << "]" << std::endl;

class Base {
public:
    virtual ~Base() { PF }
    Base() : m_b(1) {}
    Base(int b ) : m_b(b) {}

    virtual void method() { PF }
    void show_internal_num() { std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__ << "][" << m_b << "]" << std::endl; }
    int getM_b() const{ return m_b; }

private:
    int m_b;
};

class Derive : public Base {
public:
    ~Derive() { PF }
    Derive(): Base(10), m_d(2) {}
    Derive(int b, int d) : Base(b), m_d(d) {}
    Derive(const Derive *ptr) : Base(ptr->getM_b()), m_d(ptr->m_d) { PF }

    virtual void method() override { PF }
    void show_internal_num() { std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__ << "][" << m_d << "]" << std::endl; }
private:
    int m_d;
};

int main() {

    std::unique_ptr<Base> b_ptr = std::make_unique<Derive>(5, 10);
    b_ptr->method();
    b_ptr->show_internal_num();

    std::cout << "\n\n\n===============================================\n\n\n" << std::endl;

    std::unique_ptr<Derive> d_ptr = std::make_unique<Derive>(static_cast<Derive *>(b_ptr.get()));
    d_ptr->method();
    d_ptr->show_internal_num();
    d_ptr->Base::show_internal_num();

}
