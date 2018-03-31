#include <iostream>
int add(int a, int b);
void Print(int a, int b);
int main() 
{
	int a = 10;
	int b = 15;
	std::cout << add(a, b) << std::endl;

	return 0;
}

int add(int a, int b) 
{
	Print(a, b);
	return (a + b);
}

void Print(int a, int b) 
{
	std::cout << "a = [" << a << "], b = [" << b << "]" << std::endl;
}
