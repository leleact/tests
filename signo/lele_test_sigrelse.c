#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void sighandle();
int main() {

	if (sigset(SIGTERM, sighandle) == (void (*)())(-1)) {
		fprintf(stderr, "sigset error!\n");	
		exit(1);
	}
	int iCount = 0;
	while (1) {
		sigrelse(SIGTERM);
		printf("sigrelse\n");
		sleep(3);
		sighold(SIGTERM);
		printf("sighold\n");
		sleep(3);
	}
	return 0;
}

void sighandle() {
	fprintf(stdout, "sigterm caught\n");
	exit(1);
}
