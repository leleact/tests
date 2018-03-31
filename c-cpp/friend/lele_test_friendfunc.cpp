#include <iostream>
class X
{
public:
	X(int a) : a(a) {}
	void showa()
	{
		std::cout << a << std::endl;	
	}
private:
	int a;
	
	friend int geta(X &x)
	{
		return x.a;
		return 0;
	}
};


int main()
{
	X x1(5);
	x1.showa();
	std::cout << geta(x1) << std::endl;

	X x2(15);
	x2.showa();
	std::cout << geta(x2) << std::endl;

	return 0;
}
