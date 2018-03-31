#include <iostream>
#ifdef WIN32
#include <io.h>
#include <direct.h>
#else
#include <unistd.h>
#endif
#include <sys/stat.h>

int main()
{
	char dir[] = "./log_biz/";
	
#ifdef WIN32
	if (access(dir, 0) == -1)
#else
	if (access(dir, F_OK & W_OK) == -1)
#endif
	{
#ifdef WIN32
		int nRet = _mkdir(dir);
#else
		int nRet = mkdir(dir, 0755);
#endif
		if (nRet == -1)
		{
			std::cout << "make dir error\n" << std::endl;	
		}
	}

	char filepath[256];
	sprintf(filepath, "%s%s", dir, "biz.log");
	FILE *fp = fopen(filepath, "ab+");
	if (fp == NULL)
	{
		std::cout << "open file error\n" << std::endl;
		return -1;
	}

	fwrite("1111", 4, 1, fp);

	fclose(fp);
	return 0;
}
