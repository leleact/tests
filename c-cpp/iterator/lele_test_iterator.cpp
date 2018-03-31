#include <iostream>
#include <string>
#include <vector>

template<typename T>
class X {
public:
  X() = default;
  X(const T &_type_value) : type_value(_type_value) { std::cout << "lvalue\n"; }
  X(T &&_type_value) : type_value(std::move(_type_value)) { std::cout << "rvalue\n"; }
  X(const X& _x) : type_value(_x.type_value) {}
  X(X &&_x) : type_value(std::move(_x.type_value)) {}
  X &operator=(const X &_x) {
    type_value = _x.type_value; 
  }
  X &operator=(X &&_x) {
    if (this != &_x)
      type_value = std::move(_x.type_value);
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, X &_x) {
    os << _x.type_value; 
    return os;
  }
private:
  T type_value;
};

template<typename T>
void DoSomeThing(typename std::vector<X<T>>::iterator &it) {
  std::cout << *it << std::endl;
}

int main() {
  std::vector<X<std::string>> x_vec;

  X<std::string> x1("aaa");
  X<std::string> x2("bbb");
  X<std::string> x3("ccc");

  x_vec.push_back(x1);
  x_vec.push_back(x2);
  x_vec.push_back(std::move(x3));
  for (auto it = x_vec.begin(); it != x_vec.end(); ++it) {
//  std::cout << *it << std::endl;
    DoSomeThing<std::string>(it);
  }

  std::cout << "x1 = [" << x1 <<"], x2 = [" << x2 <<"], x3 = [" << x3 << "]" << std::endl;

  return 0;
}
