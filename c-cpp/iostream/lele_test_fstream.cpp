#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

	std::ofstream fs("test.txt");
	if (!fs) {
		std::cout << "create file error" << std::endl;
		return -1;
	}

	fs << "呵呵" << std::endl;

	fs.close();
}
