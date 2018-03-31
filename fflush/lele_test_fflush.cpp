#include <stdio.h>
#include <unistd.h>
int main() {
	int i = 0;
	int iCount = 0;
	while(iCount++ < 10) {
//		printf("i = [%d]\n", ++i); // 如果printf后面有'\n'会自动刷新缓冲区
		printf("i = [%d]", ++i);   // 不加fflush时，直到程序结束才回刷新缓冲区
		sleep(5);
		fflush(stdout);
	}

	return 0;
}
