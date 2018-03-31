#include <iostream>
#include <memory>

class X
{
	public:
		X (std::string n) : s (n) {}
		std::string s;
};

int main()
{
	X *x1 = new X("hhhhhhhh");
	std::shared_ptr<X> p1(x1);
	std::cout << p1.use_count() << std::endl;
	{
		std::shared_ptr<X> p3(x1);
		std::shared_ptr<X> p2 = p1;
		std::cout << p1.use_count() << std::endl;;
		std::cout << p2.use_count() << std::endl;;
		std::cout << p3.use_count() << std::endl;
	}
	std::cout << p1.use_count() << std::endl;;
	std::cout << p1->s << std::endl;;

	return 0;
}
