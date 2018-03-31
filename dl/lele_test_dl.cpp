#include <iostream>
#include <stdio.h>
#include <dlfcn.h>

int main() {
    void *pHandle = dlopen("libadd.so", RTLD_LAZY);
    if (pHandle == NULL) {
        fprintf(stdout, "dlopen error[%s]\n", dlerror());
        return -1;
    }
    int (*pfunc)(int,int) = (int (*)(int, int))dlsym(pHandle, static_cast<const char *>("add"));
    if (pfunc == NULL)
    {
        fprintf(stdout, "dlsym error[%s]\n", dlerror());
        return -1;
    }

    int x = 10;
    int y = 15;
    printf("add(%d, %d)=[%d]\n", x, y, pfunc(x, y));

    dlclose(pHandle);

    return 0;
}
