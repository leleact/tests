#include <stdio.h>
#include <string.h>
int main()
{
    char src[100];
    char des[] = "Hello";
    char *p = NULL;

    strncpy(src, p, sizeof(src)); // core dump

    printf("src = [%s]\n", src);

    return 0;
}
