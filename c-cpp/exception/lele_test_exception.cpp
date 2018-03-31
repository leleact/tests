#include <iostream>
void func1();
int main()
{
	try
	{
		func1();	
	}
	catch(std::string str)
	{
		std::cout << "Exceptopn ErrMsg[" << str << "]" << std::endl;	
	}
	catch(...)
	{
		std::cout << "Exceptopn other error" << std::endl;	
	}

	return 0;
}

void func1()
{
	std::cout << "func1 invoked" << std::endl;
	throw std::string("Test c++ exception"); // can caught by catch std::string str
	//throw std::string("Test c++ exception"); // can't been caught by catch std::string str
	std::cout << "func1 end can print?" << std::endl; // never been invoked
}
