#include <iostream>
#include <cstring>
#include <string.h>

int main(int argc, char **argv) 
{
	for(int i = 0; i < argc; ++i)
	{
		std::cout << "argc[" << i << "][" << argv[i] << "]"	 << std::endl;
	}

	char *lpStr = argv[1];
	char *strDelim = argv[2];

	char *pRet = strtok(lpStr, strDelim);
	std::cout << "strtok first invoke ret[" << pRet << "]" << std::endl;

	while(pRet != nullptr)
	{
		pRet = strtok(nullptr, strDelim);
		std::cout << "strtok invoke ret[" << pRet << "]" << std::endl;
	}

	//char src[] = "The world is beautiful";

	//char *pstr = strtok(src, " ");
	//while(pstr != nullptr) {
		//std::cout << pstr << std::endl;
		//pstr = strtok(nullptr, " ");
	//}

	return 0;
}
