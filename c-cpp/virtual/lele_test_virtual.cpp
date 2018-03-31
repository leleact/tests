#include <iostream>
#include <typeinfo>
#include <string>

class Base {
public:
	virtual ~Base() {};
	virtual void f1()
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "Base::f1() invokeed" << std::endl;
		f2();
	}

	virtual void f2()
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "Base::f2() invokeed" << std::endl;
	}
};

class Deveried : public Base {
public:
	void f1()
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "Deveried::f1() invokeed" << std::endl;
		f2();
	}

	void f2()
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "Deveried::f2() invokeed" << std::endl;
	}
};

class A : public Deveried {

	/*
	void f1() override
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "A::f1() invokeed" << std::endl;
		f2();
	}

	void f2() override
	{
		std::cout << typeid(*this).name() << std::endl;
		std::cout << "A::f2() invokeed" << std::endl;
	}
	*/

};

int main() {

	Base *p = new A();
	p->f1();

	delete p;

	return 0;
}
