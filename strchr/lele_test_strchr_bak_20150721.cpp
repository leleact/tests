#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

int main()
{
    char src[] = "aaa,bb,cccc,dddd,eeee";
    char *p = strchr(src, ',');
    std::cout << "p = [" << p << "]" << std::endl;
    std::cout << "src - p = [" << p - src << "]" << std::endl;

    char *q = strtok(src, ",");
    while (q != nullptr)
    {
        std::cout << "q = [" << q << "]" << std::endl;
        q = strtok(nullptr, ",");
    }


    return 0;
}
