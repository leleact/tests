#include <iostream>
#define MAX(x, y) x > y ? x : y //如果没有加上括号 宏中没有办法做参数运算, C99可以支持inline函数
void f();
void g();
#define MY_MACRO  do{f();g();} while(0)
#define STRING(fpAction)  s(#fpAction);
#define LIAN(x) y_##x

int main() {
  std::string STRING(444);
  std::string q("LIAN(u)");
  int a = 5;
  int b = 10;
  int c = MAX( a + 1, b + 1); // 有问题的
  std::cout << c << std::endl;

  if (1) 
    MY_MACRO;
  return 0;
}

void f() {
  std::cout << "f()" << std::endl;
}

void g() {
  std::cout << "f()" << std::endl;
}
