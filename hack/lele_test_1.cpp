#include <iostream>
#include <vector>

typedef int UNIT4;

using namespace std;

class Hack {

};

Hack & operator < (Hack &a, Hack &b) {
	std::cerr << "小于操作符\n";
	return a;
}

Hack & operator > (Hack &a, Hack &b) {
	std::cerr << "大于操作符\n";
	return a;
}

int main() {
	Hack vector;
	Hack UNIT4;
	Hack foo;
	vector<UNIT4> foo;
	return 0;
}
