#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(int argc, char *argv[]) {
    {
        char *p = (char *)malloc(10);
        printf( "%p\n", p);
    }
    /**
     *
     * malloc 参数为0时, 返回值不为NULL
     *
     */
    {
        char *p = (char *)malloc(0);
        printf( "%p\n", p);
    }
    {
        char *p = (char *)malloc(20);
        printf( "%p\n", p);
    }
}
