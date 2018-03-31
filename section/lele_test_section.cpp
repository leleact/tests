#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

typedef struct {
	std::string section_name;
	std::map<std::string, std::string> cfg;
} configure;

int main(int argc, char *argv[]) {
	if (argc != 2)
		std::cerr << "Need File Name" << std::endl;
	std::vector<configure> vcCfg;
	std::string comment = ";#";
	std::fstream fs(argv[1], std::fstream::in);
	if (!fs) {
		std::cerr << "Non File" << std::endl;
		return -1;
	}

	std::string strTemp;
	std::string currSection = "DEFAULT";
	while(true) {
		std::getline(fs, strTemp);
		if (fs.eof())
			break;
		bool isComment = false;
		for_each(comment.begin(), comment.end(), [&](char c){ 
				if (strTemp[0] == c)
					isComment = true;
				});
		if (isComment)
			continue;
		
		std::cout << strTemp << "|" << std::endl;
	}
	fs.close();
	return 0;
}
