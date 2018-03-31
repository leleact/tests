#include <iostream>
#include <functional>

class A {

public:
    virtual std::size_t fun(const std::string& str) { return str.size(); }
    virtual std::size_t fun_1(std::string& str) { return str.size() + 2; }

};

class B : public A {

public:
    virtual std::size_t fun(const std::string& str) { return str.size() + 1; }
};

std::size_t fun2(const std::string& str) { return str.size(); }

int main() {
    {
        std::function<std::size_t (const std::string&)> f = std::bind(fun2, std::placeholders::_1);
        auto f2 = std::bind(fun2, std::placeholders::_1);
        std::string s = "aaabbc";
        std::cout << f( s ) << std::endl;
        std::cout << f2( s ) << std::endl;
    }

    {
        A a;
        std::function<std::size_t ( const std::string&)> f = std::bind(&A::fun, a, std::placeholders::_1);
        std::string s = "aaabbc";
        std::cout << f( s ) << std::endl;
    }

    {
        B a;
        std::function<std::size_t ( const std::string&)> f = std::bind(&A::fun, a, std::placeholders::_1);
        std::string s = "aaabbc";
        std::cout << f( s ) << std::endl;
    }

    {
        A a;
        std::function<std::size_t (std::string&)> f = std::bind(&A::fun_1, a, std::placeholders::_1);
        std::string s = "aaabbc";
        std::cout << f( s ) << std::endl;
    }
    return 0;
}
