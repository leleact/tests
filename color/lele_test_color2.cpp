#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <assert.h>

#define PRINT_STDERR(x) fprintf(stderr, "\033[5;7;31m%s\033[00m\n", x);

int main(int argc, char *argv[]) {
    //for (int i = 0; i < 10; i++) {
        //for (int j = 30; j < 55; j++) {
            //for (int k = 30; k < 55; k++)  {
                //fprintf(stdout, "\033[%d;%d;%dm[%d][%d][%d]\033[m\n", i, j, k, i, j, k);
            //}
        //}
    //}
    if (argc != 4) {
        PRINT_STDERR("Argument stderr");
        return -1;
    }
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    int k = atoi(argv[3]);
    fprintf(stdout, "\033[%d;%d;%dm[%d][%d][%d]\033[m\n", i, j, k, i, j, k);
}
