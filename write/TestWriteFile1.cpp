#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
int main() {
	int fd = open("a.txt", O_RDWR|O_CREAT, 0644);
	if (-1 == fd)
	{
		std::cerr << "open error" << std::endl;
		return -1;
	}

	std::string str;
	while(std::cin >> str)
	{
		write(fd, str.c_str(), str.size());	
	}
	return 0;
}
