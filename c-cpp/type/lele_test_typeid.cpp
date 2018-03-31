#include <iostream>
#include <typeinfo>

template<typename T>
struct A {
	typedef T type;
};

class Base111
{};

int main() {
	A<int>::type a = 10;
	std::cout << "type of a is " << typeid(a).name() << std::endl;
	std::cout << "a=" << a << std::endl;

	Base111 b;
	std::cout << "type of Base111 is " << typeid(b).type_info::name() << std::endl; // 7Base111 7表示类名长度

	return 0;
}
