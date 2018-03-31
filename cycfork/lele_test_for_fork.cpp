#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
using namespace std;
int main() {
	int iCount = 3;
	int i = 0;

	for(; i < iCount; i++) {
		pid_t pid = fork();	
		if(pid < 0) {
			cerr << "fork failed!" << endl;
			exit(1);
		}

		if(pid == 0) {
			/* child */	
			cout << "child, pid = [" << getpid() << "], ppid = [" << getppid() << "]" << endl;
		}
		else {
			/* parent */	
			cout << "parent, pid = [" << getpid() << "], ppid = [" << getppid() << "]" << endl;
		}
	}
	sleep(100);
	return 0;
}
