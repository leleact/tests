#include <iostream>
inline int getMax(int a, int b) { return a>b?a:b;}
int main()
{
	int a = 10;
	int b = 14;

	int c = getMax(a, b);

	std::cout << c << std::endl;
	return 0;
}
