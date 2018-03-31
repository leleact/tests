#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string& str, const std::string& delim);

int main(int argc, char *argv[]) {

    std::ifstream in("a.txt", std::fstream::in|std::fstream::binary);

    while(in.good()) {
        std::string buff;
        std::getline(in, buff);
        std::vector<std::string> v = split(buff, " ");
        if (v.size() >= 2)
            std::cout << "INSERT INTO tpam_resp_code_info (TPAM_RESP_CODE, RESP_CODE, TPAM_RESP_MSG, PAGY_CODE, TPAM_RESP_STATE) VALUES ('" << v[0] << "', '9999', '" << v[1] << "', '312', '00');" << std::endl;
        else
            std::cout << "ERROR str [" << buff << "]" << std::endl;
    }

    return 0;
}



std::vector<std::string> split(const std::string& str, const std::string& delim) {
    std::vector<std::string> vec;

    std::string::size_type begin = 0;
    std::string::size_type end = 0;
    while((end = str.find(delim, begin)) != std::string::npos) {
        std::string temp = str.substr(begin, end - begin);
        if (temp.length() > 0)
            vec.push_back(str.substr(begin, end - begin));
        begin = end + delim.length();
    }

    if (begin < str.length()) {
        vec.push_back(str.substr(begin, str.length() - begin));
    }
    return vec;
}
