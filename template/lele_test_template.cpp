#include <iostream>
template<typename T>
T add(T &a, T &b);

template<typename T>
T add(T a, T b);
int main() {
	std::cout << "a + b = [" << add(4, 6) << "]" << std::endl;
	return 0;
}

template<typename T>
T add(T &a, T &b) {
	return a + b;
}

template<typename T>
T add(T a, T b) {
	return a + b;
}
