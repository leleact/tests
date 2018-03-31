

#include <iostream>

#define Lele(q) #q

int main()
{
	const char *p = Lele(aaa);
	const char *p1 = Lele("aaa");
	std::cout << p << "," << p1 << std::endl;
	return 0;
}
