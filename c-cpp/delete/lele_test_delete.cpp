#include <iostream>
#include <string>
template <typename T>
struct X {
  X() = default;
  X(X &x) = delete;
  T type_value;
};

int main() {
  X<std::string> x;
  /// oerror call to deleted constructor of 'X<std::string>'
  /// X<std::string> x1 = x;

  return 0;
}
