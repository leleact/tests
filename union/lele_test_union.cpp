#include <stdio.h>
int main() {
	union uN {
		int i;
		char c;
	};

	union uN var;

	var.i = 32;
	var.c = 48;

	printf("var.i = [%d]\n", var.i);
	printf("var.c = [%d]\n", var.c);

	return 0;
}
