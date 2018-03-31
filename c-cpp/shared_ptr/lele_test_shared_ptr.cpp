#include <iostream>
#include <memory>

class X {
public:
  ~X() { std::cout << "use destruct" << std::endl; }
  int i;
};

void TestSharedPtr();
int main() {
  TestSharedPtr();

  return 0;
}

#include <vector>
#include <string>
#include <list>
void TestSharedPtr() {
  using namespace std;
  shared_ptr<string> p1;
  shared_ptr<list<int>> p2;
  if (p1 && p1->empty()) {
    *p1 = "hi";
  }
  shared_ptr<int> p3 = make_shared<int>(42);
  shared_ptr<string> p4 = make_shared<string>(10, '9');
  shared_ptr<int> p5 = make_shared<int>();

  X x;
  cout << "before lambda x.i = [" << x.i << "]" << endl;
  auto f = [](X arg) { return make_shared<X>(arg); }(x);
  cout << "after lambda x.i = [" << x.i << "]" << endl;
  cout << "f->i = [" << f->i << "]" << endl;
}
