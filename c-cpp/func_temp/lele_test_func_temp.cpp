#include <iostream>
#include <functional>

int f1(int a, int b);

int main()
{
	std::function<int(int, int)> f;
	f = f1;

	std::cout << f(3, 4) << std::endl;

	return 0;
}

int f1(int a, int b)
{
	return a + b;
}
