#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <iterator>

std::size_t calculateMetrics(const std::string&);

int main(int argc, char *argv[]) {
	char c = 0;
	std::string filename;
	int fileflag = 0;
	while ((c = getopt(argc, argv, "f:")) != -1) {
		switch(c) {
			case 'f':
				filename = optarg;
				fileflag = 1;
				break;
			default:
				std::cout << "use " << argv[0] << " -f [filename]" << std::endl;
				exit(EXIT_FAILURE);
		}
	}

	if (fileflag == 0) {
		std::cout << "use " << argv[0] << " -f [filename]" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::fstream fs(filename.c_str(), std::fstream::in);
	if (!fs) {
		std::cerr << "open file " << filename << " error!" << std::endl;
		exit(EXIT_FAILURE);
	}

	while(!fs.eof()) {
		std::string s;
		std::getline(fs, s);
		std::size_t start = s.find("8=");
		if (start == std::string::npos) {
			continue;
		}
		std::size_t end = s.find("10=");
		if (end == std::string::npos) {
			continue;	
		}
		std::string checkString = s.substr(start, end-start);
		std::cout << "[" << checkString << "]:[" << std::setw(3) << std::setfill('0') << calculateMetrics(checkString) << "]" << std::endl;
	}
	return 0;
}

std::size_t calculateMetrics(const std::string &s) {
	int total = 0;
	std::for_each(s.cbegin(), s.cend(), [ &total ](const unsigned char c){ total += c; });
	return total % 256;
}
