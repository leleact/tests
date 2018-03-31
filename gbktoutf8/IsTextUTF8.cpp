#include <iostream>
int IsTextUTF8(char* str,long long length)
{
	int i;
	int nBytes=0;				//UFT8可用1-6个字节编码,ASCII用一个字节
	u_char chr;
	bool bAllAscii = true;		//如果全部都是ASCII, 说明不是UTF-8
	for(i=0;i<length;i++)
	{
		chr= *(str+i);
		if( (chr&0x80) != 0 ) // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx
			bAllAscii= false;
		if(nBytes==0) //如果不是ASCII码,应该是多字节符,计算字节数
		{
			if(chr>=0x80)
			{
				if(chr>=0xFC&&chr<=0xFD)
					nBytes=6;
				else if(chr>=0xF8)
					nBytes=5;
				else if(chr>=0xF0)
					nBytes=4;
				else if(chr>=0xE0)
					nBytes=3;
				else if(chr>=0xC0)
					nBytes=2;
				else
				{
					return false;
				}
				nBytes--;
			}
		}
		else //多字节符的非首字节,应为 10xxxxxx
		{
			if( (chr&0xC0) != 0x80 )
			{
				return false;
			}
			nBytes--;
		}
	}
	if( nBytes > 0 ) //违返规则
	{
		return false;
	}
	if( bAllAscii ) //如果全部都是ASCII, 说明不是UTF-8
	{
		return false;
	}
	return true;
}


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
	if (nRet == -1)
	{
		iconv_close(cd);
        return -1;
	}
	
    iconv_close(cd);
    return 0;
}

#include <fstream>
#include <sstream>
int main()
{
	std::fstream file;	
	std::stringstream sstr;
	file.open("mpca.xml");
	sstr << file.rdbuf();
	file.close();

	std::string str = sstr.str();
	std::size_t nsize = str.size(); 
	std::cout << IsTextUTF8((char *)str.c_str(), nsize) << std::endl;;
	/*
	char *out = (char *)malloc(nsize * 2);
	std::size_t nOutsize = nsize * 2;

	char *src = const_cast<char *>(str.c_str());
	GbkToUtf8(src, nsize, out, nOutsize);

	std::cout << out << std::endl;
	*/
	
	return 0;
}
