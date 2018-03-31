/**
 * 1. 测试基类的static成员是否可以继承
 * 2. 测试基类的static成员函数是否可以继承
 */

#include <iostream>
#include <string>
#include <cstring>
class CBase {
public:
  static int m_nTest;
  static int Getm_nTest() { return m_nTest; };
  static void Setm_nTest(int nTest) { m_nTest = nTest; };
  CBase() {};
  CBase(std::string &strName) : m_strName(strName) { }

private:
  std::string m_strName;
};

class CDerive : public CBase {

};


int CBase::m_nTest = 10; // 必须在类外初始化, 不初始化或者在类中初始化，或者在函数中初始化都会编译错误

int main() {

  // int CBase::m_nTest = 10; 不能再函数中定义
  CBase b;
  std::cout << b.Getm_nTest() << std::endl; // 10

  b.Setm_nTest(15);

  CDerive d;
  std::cout << d.Getm_nTest() << std::endl;  // 15

  d.Setm_nTest(1000);

  CDerive d1;
  std::cout << d1.Getm_nTest() << std::endl;

  std::cout << b.Getm_nTest() << std::endl;

  return 0;
}

// 1. static成员可以继承
// 2. static成员函数可以继承
// 3. static函数不能是virtual
// 4. 子类和父类公用一个static变量
