#include <iostream>
#include <cstring>
#include <string>
#include <assert.h>

namespace test {
    int strchr(int argc, char *argv[]);
}

int main(int argc, char *argv[]) {
    return test::strchr(argc, argv);
}

/**
 *  main strchr 时, 
 *  char *strchr(const char *s, int c);
 *  但是在 <string.h>中
 *  char *strchr (char *__s, int __c)
 *  const char *strchr (const char *__s, int __c)
 */
namespace test {
    int strchr(int argc, char *argv[]) {
        {
            const char *str = "ab,df,,,ff";
            int delim = ',';
            const char *pR = ::strchr(str, delim);
            assert( pR == str + 2 );

            const char *pR1 = ::strchr(pR + 1, delim);
            assert( pR1 == pR + 1 + 2 );
        }
        return 0;
    }
}

int main1(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "][" << argv[i] << "]"	<< std::endl;
    }

    char *pstr = argv[1];
    char cDot = argv[2][0];
    char *p1 = strchr(pstr, cDot);
    char *p2 = strchr(p1 + 1, cDot);
    int offset = p2 - p1;
    char strOrgiMsgType[10];
    strncpy(strOrgiMsgType, p1 + 1, offset - 1);
    std::cout << strOrgiMsgType << std::endl;
    int nOrgiMsgType = atoi(strOrgiMsgType);
    std::cout << nOrgiMsgType << std::endl;
    return 0;
}
