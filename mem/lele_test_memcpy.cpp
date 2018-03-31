#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char **argv) {

	char s[] = "Hello World";
	char des[10 + 1];

	memset(des, 0x00, sizeof(des));
	memcpy(des, s + 4, 6);

	std::cout << des << std::endl;

	return 0;
}
