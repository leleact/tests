#include <iostream>
#include <vector>
#include <exception>
#include <string>

class TestException : public std::exception {
public:
  /*
  TestException() throw() {
    std::cout << "TestException" << std::endl;
  }
  */

  virtual const char * what() const throw() override {
    return "exception caught";
  };
};

class MyException /*: public std::exception*/ 
{
public:
	virtual const char *what() const noexcept {
		return "my exception";
	}
};

void func() throw (std::string) ;
void func1() noexcept;
void func2() noexcept(0);
void func3();

int main() {

#if 1
  std::string str = "aaa";

try {
  func();
} /* catch( std::vector<int>() ) {
  std::cout << "11" << std::endl;
}
*/
catch (std::string e) {
  std::cout << "std::string exception" << std::endl;
}
catch (int n) {
  std::cout << "int exception" << std::endl;
}
  /*
  if (str == "aaa") {
    throw std::string(); 
  }
  */

//try {
//  func1();
// } catch (int n) {
//  std::cout << "func1 int exception" << std::endl;
//}


try
{
   func2();
} 
catch (int n) 
{
   std::cout << "func2 int exception n[" << n << "]" << std::endl;
}

//  func2(); /* 不捕获会core dump */
#endif

/*
try {
  func3();
} catch(MyException e) {
  std::cout << "func3 MyException caughted" << std::endl;
}
*/

  func3();

  return 0;
}

/**
 * C++11 弃用throw()这种用法, 改用noexcept修饰符号
 */
void func() throw (std::string) {
  std::cout << "func called" << std::endl;
  if (1)
    // throw int(); // 直接退出, 不能捕获
    throw std::string("hehe"); // 可以被捕获与处理
}

void func1() noexcept {
  std::cout << "func1 called" << std::endl;
  throw 1; // 因为noexcpt 无法被捕获
}

// void func2 {
void func2() noexcept(0) {
  std::cout << "func2 called" << std::endl;
  throw 1; // noexcpt(0) 相当于没有noexcpt 异常可以被捕获
}

void func3() {
//  throw MyException();
  throw MyException();
}
