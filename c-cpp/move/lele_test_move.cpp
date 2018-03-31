#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>

namespace v_before_20170907 {
#define DEBUG
#ifndef USING_STD_STRING
class X {
using string = std::string;
public:
  X() = default;
  X(const string &s) : s(s) {};
  X(const char *p) {
    s = p;
  }
  X(string &&s) : s(std::move(s)) {}
  X(const X &x) : s(x.s) {}
  X(X&& x) noexcept : s(std::move(x.s)) {
#ifdef DEBUG
    std::cout << "X&& move" << std::endl;
#endif
  }
  X& operator=(const X &x) {
    s = x.s;
    return *this;
  }
  X& operator=(X&& x) {
    if (this != &x) {
      s = std::move(x.s);
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream &os, X &x) {
    os << x.s;
    return os;
  }
private:
  string s;
};
#else
using X = std::string;
#endif
int main() {
  std::string s1 = "aa";
  std::string s2 = "bb";
  X x1 = "aa";
  X x2 = "bb";
  X x3(s1);
  X x4(s2);
  std::vector<X> xvec;
  xvec.push_back(x1);
  xvec.push_back(std::move(x2));
  xvec.push_back(x3);
  xvec.push_back(std::move(x4));

  for (X& x : xvec) std::cout << x << " ";
  std::cout << std::endl;

  std::cout << "x1 = [" << x1 << "], x2 = [" << x2 << "]" << std::endl;
  std::cout << "x3 = [" << x3 << "], x4 = [" << x4 << "]" << std::endl;

  return 0;
}
}


namespace v_20170907 {

    void f(std::vector<std::string> str) {
        const std::vector<std::string>& v2 = std::move(str); // 编译以及运行正常
        //std::vector<std::string>& v2 = std::move(str); // 编译报错
    }

    int main(int argc, char *argv[]) {
        std::vector<std::string>  vec = {"aaa", "bbb"};
        f(vec);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    return v_20170907::main(argc, argv);
}
