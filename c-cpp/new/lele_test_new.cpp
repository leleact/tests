#include <iostream>
#include <string>
#include <cstring>
class Base {
public:
  Base() {
    for (int i = 0; i < 10; ++i) {
      str_arr[i]  = "aaa";
    }
  }
  std::string str_arr[10];
};

class X {
public:
  X() {
    std::cout << "default construct" << std::endl;
  }

  Base b[10];
};

int main() {
  std::cout << "sizeof Base = [" << sizeof(Base) << "]" << std::endl; 
  std::cout << "sizeof X = [" << sizeof(X) << "]" << std::endl; 
}
