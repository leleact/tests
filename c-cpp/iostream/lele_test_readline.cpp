#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	std::fstream fs("demo.txt", std::fstream::in);

	std::string strbuff;

	while(!std::getline(fs, strbuff).eof()) {
		std::cout << strbuff << std::endl;
	}

	if (strbuff.size() != 0) {
		std::cout << strbuff << std::endl;	
	}

	return 0;
}
