#include <iostream>
bool is_blank(const char *lpsrc)
{
	const char *pTemp = lpsrc;
	if (pTemp == NULL)
		return true;

	while(*pTemp == ' ' && *pTemp != '\0')
	{
		pTemp++;	
	}

	if (*pTemp == '\0')
	{
		return true;	
	}

	return false;
}

int main()
{
	std::cout << "src=[aa], ret=[" << is_blank("aa") << "]" << std::endl;
	std::cout << "src=[ aa], ret=[" << is_blank(" aa") << "]" << std::endl;
	std::cout << "src=[ aa ], ret=[" << is_blank(" aa ") << "]" << std::endl;
	std::cout << "src=[  ], ret=[" << is_blank("  ") << "]" << std::endl;
	std::cout << "src=[], ret=[" << is_blank("") << "]" << std::endl;
	std::cout << "src=[null], ret=[" << is_blank(NULL) << "]" << std::endl;
	std::cout << "src=[ a], ret=[" << is_blank(" a") << "]" << std::endl;
	std::cout << "src=[a ], ret=[" << is_blank("a ") << "]" << std::endl;
	std::cout << "src=[a], ret=[" << is_blank("a") << "]" << std::endl;
	std::cout << "src=[ ], ret=[" << is_blank(" ") << "]" << std::endl;
	return 0;
}
