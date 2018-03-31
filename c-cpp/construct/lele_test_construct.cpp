#include <iostream>

class X {
public:
	X() : M_count(0) {};
	X(int i) : M_count(i) {  };

private:
	const int M_count;
};


int main(int argc, char *argv[]) {
	X x;
}
