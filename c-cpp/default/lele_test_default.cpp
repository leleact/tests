#include <iostream>
#include <string>
#include <memory>
class X {
public:
  X() = default;
  X(int a, std::string &s) : i(a), s(s) {}
  int  Show() {
    std::cout << i << std::endl; 
    return i;
  }
private:
  int i;
  std::string s;
};

int main(int argc, char **argv) {
  X x1;
  std::cout << x1.Show() << std::endl;
  
  std::string s = "a";
  X x(3, s);
  std::shared_ptr<X> ptr = std::make_shared<X>();
  std::cout << ptr->Show() << std::endl;
  return 0;
}
