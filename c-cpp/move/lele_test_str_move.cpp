#include <iostream>
#include <string>
#include <utility>

class X {
public:
    X() = default;
    X(const X &x) : s(x.s) {}
    X(X &&x) : s(std::move(x.s)) {}
    X &operator=(const X &x) {
        s = x.s;
        return *this;
    }
    X &operator=(X &&x) {
        s = std::move(x.s);
        return *this;
    }

private:
    std::string s;
};

int main() {
    std::string s1 = "hi!";
    std::string s2;

    s2 = std::move(std::string("bye!"));
    std::cout << "s2 = [" << s2 << "]" << std::endl;

    s2 = std::move(s1);
    std::cout << "s2 = [" << s2 << "], s1 = [" << s1 << "]" << std::endl;

    return 0;
}
