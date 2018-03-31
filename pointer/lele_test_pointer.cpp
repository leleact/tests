#include <iostream>
#include <memory>
template<typename T>
struct X {
  T type_value;
  X() = default;
  X(T &_type_value) : type_value(_type_value) {}
  X(const X &_x) : type_value(_x.type_value) {};
};

template<typename T>
bool TestRef(X<T> &x) {
  std::cout << x.type_value << std::endl;
  return true;
}

int main() {
  std::shared_ptr<X<int>> ptr_x(new X<int>());

  // error
  TestRef(ptr_x);

  return 0;
}
