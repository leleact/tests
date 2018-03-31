// 测试struct类的继承方式
#include <iostream>
#include <string>
struct A
{
	int a;
};

class B : A
{
public:
	B(int b) : b(b) {}
	void show()
	{
		std::cout << a << std::endl;	
	}

private:
	int b;

};

class X
{
public:
	int x1;
private:
	int x2;
};

class Y : X
{
public:
	void show()
	{
		std::cout << x1 << x2 << std::endl;	
	}
};

class Z : public X
{
};


int main()
{
	//B b(4);
	//b.show();
	//std::cout << b.a << std::endl;

	Y y;
	std::cout << y.x1 << std::endl;
	Z z;
	std::cout << z.x1 << z.x2 << std::endl;
}

// 看来默认继承还是私有继承嘛
// 派生类不能访问基类私有变量
// 派生类私有继承基类，可以访问公有变量，外部扔不能访问公有变量
