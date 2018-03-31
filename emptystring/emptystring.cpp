#include <iostream>
#include <cstring>
int main() {
	std::string s;
	std::cout << "s = " << s << std::endl;
	std::cout << "s.size = " << s.size() << std::endl;
	std::cout << "s.capacity = " << s.capacity() << std::endl;
	std::cout << "s[0] = [" << s[0] << "]" << std::endl;

	s = "hello";
	std::cout << "s = " << s << std::endl;
	std::cout << "s.size = " << s.size() << std::endl;
	std::cout << "s.capacity = " << s.capacity() << std::endl;
	std::cout << "s[0] = [" << s[0] << "]" << std::endl;
	return 0;
}
