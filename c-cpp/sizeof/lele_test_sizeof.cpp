#include <stdio.h>

int nTest(char * );

int main() {
	char s[] = "Hello";
	printf("sizeof(\"Hello\") : [%ld]\n", sizeof("Hello"));
	printf("sizeof(int) : [%ld]\n", sizeof(int));
	nTest(s);
	return 0;
}

int nTest(char * s) {
	printf("sizeof pointer of char[] : [%ld]\n", sizeof(s));
	return 0;
}
