#include <iostream>
struct Base {
  void f() {
    std::cout << "Base f()" << std::endl; 
  }

  virtual void g() {
    std::cout << "Base g()" << std::endl; 
  }
};

struct Deveried : public Base {
  void f() {
    std::cout << "Deveried f()" << std::endl; 
  }

  void g() {
    std::cout << "Deveried g()"  << std::endl;
  }
};

int main() {
  /*
  Deveried d;
  d.f();
  d.g();

  Base b = (Base)d;
  b.g();

  Base *pb = new Deveried();
  pb->g();
  Base *pb1 = new Base();
  Deveried *pd = (Deveried *)pb1;
  pd->g();
  */

  Base b;
  Deveried d;
  Deveried *pd = (Deveried *)&b;
  pd->f();
  pd->g();

  return 0;
}
