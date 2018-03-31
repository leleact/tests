/***************************************************************************//*
 * 测试类中的函数没有实现是否能编译通过
 * 测试抽象类的派生类中函数没有实现能否编译通过
 *****************************************************************************/
#include <iostream>
#include "obstract.hpp"

class X
{
public:
	void func1();
	void func2();
};

void X::func2()
{
	std::cout << "X::func2() invoked!" << std::endl;
	return ;
}

int main()
{
	X x;
	x.func2();

	CC c;
	c.func2();
	return 0;
}
