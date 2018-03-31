#include <stdio.h>
#include <unistd.h>
static inline void loadBar(int, int, int, int);
static inline void loadBar(int x, int n, int r, int w) {
    if ( r > n )
        r = n;

    // Only update r times.
    if ( x % (n/r) != 0 ) return;

    // Calculuate the ratio of complete-to-incomplete.
    float ratio = x/(float)n;
    int   c     = ratio * w;

    // Show the percentage complete.
    printf("%3d%% [", (int)(ratio*100) );

    // Show the load bar.
    for (int x=0; x<c; x++)
        printf("=");

    printf(">");

    for (int x=c; x<w; x++)
        printf(" ");

    // ANSI Control codes to go back to the
    // previous line and clear it.
    printf("]\033[0G");
    fflush(stdout);
}

int main(int argc, char *argv[])
{
    int i = 0;
    for (; i <= 100; i++)
    {
        loadBar(i, 100, 200, 80);
        usleep(100000);
    }
    printf("\n");
//    printf("\033[K");
    return 0;
}
