#include <stdio.h>
#include <string.h>
#include <assert.h>

int strchr_test( int argc, char *argv[] );

int main(int argc, char *argv[]) {
    return strchr_test( argc, argv );
}

/**
 * strchr 在C语言下, 返回值不用const
 */
int strchr_test( int argc, char *argv[] ) {
    const char *pStr = "a,bc, dd,,,fr";
    char *pR = strchr( pStr, ',');
    assert( pR == pStr + 1 );

    char *pR1 = strchr( pR + 1, ',' );
    assert( pR1 == pR + 1 + 2 );

    return 0;
}
