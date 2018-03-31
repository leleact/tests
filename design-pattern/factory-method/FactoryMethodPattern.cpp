#include <iostream>
#include <memory>

#define PF std::cout << "(" << __FILE__ << ":" << __LINE__ << ")[" << __PRETTY_FUNCTION__ << "]" << std::endl;

class Product {
public:
    virtual void method() = 0;
};

class Product1 : public Product {
public:
    virtual void method() override {
        PF
    }
};

class Product2 : public Product {
public:
    virtual void method() override {
        PF
    }
};

template <typename ProductType>
class Factory {
public:
    std::unique_ptr<ProductType> createProduct1() {
        static_assert( std::is_base_of<ProductType, Product1>::value, "Type Argument Exception");
        return std::make_unique<Product1>();
    }

    std::unique_ptr<ProductType> createProduct2() {
        static_assert( std::is_base_of<ProductType, Product2>::value, "Type Argument Exception");
        return std::make_unique<Product2>();
    }
};

int main() {
    Factory<Product> factory;
    std::unique_ptr<Product> ptr1 = factory.createProduct1();
    ptr1->method();
    std::unique_ptr<Product> ptr2 = factory.createProduct2();
    ptr2->method();
}
