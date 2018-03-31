#include <iostream>
#include <sstream>

namespace test {

int wchar(int argc, char *argv[]);

}

int main(int argc, char *argv[]) {
    return test::wchar(argc, argv);
}

namespace test {

int wchar(int argc, char *argv[]) {
    std::wstring str = L"abcABC";
    std::wcout << "[" << str << "]" << std::endl;

    std::wstring str1 = L"abc中国ABC";
    std::wcout << "[" << str1 << "]" << std::endl;
    return 0;
}

}
