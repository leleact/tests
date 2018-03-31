#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <xstring>
#include <Windows.h>
#include <stdio.h>


using namespace std;

int GBKToUTF8(const std::string& strGBK, std::string& strUTF8)
{
	int nRet = 0, nWLen = 0, nMLen = 0, nTemp = 0;
	WCHAR *lpWStr = NULL;
	char *lpStr = NULL;

	strUTF8 = "";

	if (strGBK.empty())
	{
		return 0;
	}

	nWLen = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	if (nWLen == 0)
	{
		nRet = -1;
		goto gbk_to_utf8_err_flag;
	}

	lpWStr = new WCHAR[nWLen];
	if (lpWStr == NULL)
	{
		nRet = -1;
		goto gbk_to_utf8_err_flag;
	}
	
	nTemp = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, lpWStr, nWLen);
	if (nTemp == 0)
	{
		nRet = -1;
		goto gbk_to_utf8_err_flag;
	}
	
	nMLen = WideCharToMultiByte(CP_UTF8, 0, lpWStr, -1, NULL, 0, NULL, NULL);
	if (nMLen == 0)
	{
		nRet = -1;
		goto gbk_to_utf8_err_flag;
	}

	lpStr = new char[nMLen];
	if (lpStr == NULL)
	{
		nRet = -1;
		goto gbk_to_utf8_err_flag;
	}

	nTemp = WideCharToMultiByte(CP_UTF8, 0, lpWStr, -1, lpStr, nMLen, NULL, NULL);
	if (nTemp == 0)
	{
		nRet = -1;
		goto gbk_to_utf8_err_flag;
	}

	nRet = 0;
	strUTF8 = lpStr;


gbk_to_utf8_err_flag:
	if (lpWStr)
	{
		delete []lpWStr;
	}

	if (lpStr)
	{
		delete []lpStr;
	}

	return nRet;
}


int main(int argc, char *argv[])
{
	string strUTF8;
	char szMsg[] = "Hello, ´ó¼ÒºÃ£¡";
	if (GBKToUTF8(szMsg, strUTF8) != 0)
	{
		cout << "fail" << endl;
	}
	else
	{
		FILE * fp2 = fopen("aa", "wb");
		cout << strUTF8 << endl;
		FILE *fp = NULL;
		fopen_s(&fp, "utf8.txt", "wb");
		if (fp)
		{
			fwrite(strUTF8.c_str(), strUTF8.length(), 1, fp);
			fclose(fp);
		}
	}

	system("pause");

	return 0;
}