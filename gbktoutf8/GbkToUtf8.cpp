#include <iostream>
#include <cstring>
#include <iconv.h>
#include <errno.h>
int GbkToUtf8(char *lpSrc, size_t szInlen, char *lpDes, size_t szOutlen)
{
	if (lpSrc == NULL || lpDes == NULL || szInlen <= 0 || szOutlen <= 0)
	{
		return -1;
	}
	iconv_t cd;
	char **pIn = &lpSrc;
	char **pOut = &lpDes;
	
	cd = iconv_open("UTF-8", "GBK");
	if (cd == iconv_t(-1))
	{
		return -1;
	}
	
	memset(lpDes, 0x00, szOutlen);
	std::size_t nRet = 0;
    nRet = iconv(cd, pIn, &szInlen, pOut, &szOutlen) ;
	std::cout << "nRet = [" << nRet << "]" << std::endl;
	std::cout << "errno = [" << errno << "], ErrMsg = [" << strerror(errno) << "]" << std::endl;
	if (nRet == -1)
	{
		std::cout << "nRet 能等于 -1？" << std::endl;
		iconv_close(cd);
        return -1;
	}
	
    iconv_close(cd);
    return 0;
}

int main()
{
	char src[256] = "Hello, 你好";
	char des[256] = { 0 };
	std::size_t nLenIn = 256;
	std::size_t nLenOut = 256;
	int nRet = 0;
	nRet = GbkToUtf8(src, nLenIn, des, nLenOut);
	if (nRet)
	{
		std::cout << "GbkToUtf8 error" << std::endl;
	}
	
	std::cout << "des = [" << des << "]" << std::endl;
	return 0;
}
