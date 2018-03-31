#include <iostream>
class X {
public:
  X(int i = 0) : m(i) {
    std::cout << "constructor int i = 0" << std::endl;
  };
  int mf(int i) {
    int old = m; 
    m = i;
    return old;
  }
private:
  int m;
};

struct Date {
  int y;
  int m;
  int d;
  Date (int a = 0, int b = 0, int c = 0) : y(a), m(b), d(c) {}
  Date (const Date &d) {
    std::cout << "copy constructor" << std::endl;
    this->d = d.d; 
    m = d.m;
    y = d.y;
  }

  void Init(int dd, int mm, int yy) {
    d = dd; 
    m = mm;
    y = yy;
  }
  void AddYear(int n) { y = y + n; }
  void AddMonth(int n) { m = m + n; }
  void AddDay(int n) { d = d + n; }
};

struct Base {
  virtual void func() const {
    std::cout << "Base func" << std::endl;
  }
};

struct Derived1 : public Base {
  void func() const override {
    std::cout << "Deriv1 func" << std::endl; 
  }
};

struct Derived2 : public Base {
  void func() const override {
    std::cout << "Deriv2 func" << std::endl; 
  }
};

void Func(const Base &b) {
  std::cout << "const Base &" << " ";
  b.func();
}

void Func(const Base *pb) {
  std::cout << "const Base *pb" << " ";
  pb->func();
}

int XTest();
int DateTest();
int ClassTest();
int main() {
  //XTest();
  //DateTest();
  ClassTest();
}

int ClassTest() {
  Base b;
  Derived1 b1;
  Derived2 b2;

  Func(b);
  Func(b1);
  Func(b2);

  Func(Base());
  Func(Derived1());
  Func(Derived2());

  Base *pb = new Base();
  Base *pb1 = new Derived1();
  Base *pb2 = new Derived2();

  Func(pb);
  Func(pb1);
  Func(pb2);

  return 0;
}

int DateTest() {
  Date d;
  //Date d(); //error
  Date d2(1);
  Date d1{d};
  return 0;
}

int XTest() {
  X var{7};
  return 0;
}
