#include <iostream>
#include <vector>
int TestBound();
int f();
int main() {
  TestBound();

  return 0;
}

int TestBound() {
  std::vector<int> vi(100);
  int &&r1 = f();
  int &r2 = vi[0];
  int &r3 = r1;
  int &&r4 = vi[0] * f();

  int &&rr1 = 100;
  int &&rr2 = std::move(rr1);
  std::cout << rr1 << " " << rr2 << std::endl;

  int rr3 = 10;
  int &&rr4 = std::move(rr3);
  std::cout << rr3 << " " << rr4 << std::endl;
  return 0;
}

int f() {
  return 10;
}
