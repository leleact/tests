#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

void sig_handle(int signum);

int main(int argc, char *argv[]) {
    struct sigaction act;
    struct sigaction oldact;
    memset(&act, 0x00, sizeof(act));
    act.sa_handler = sig_handle;
    if ( sigfillset(&act.sa_mask ) == -1 ) {
        fprintf( stderr, "sigfillset invoke error\n"); 
        exit(1); 
    }

    if ( sigaction( SIGCHLD, &act, &oldact) ) {
       fprintf(stderr, "sigaction invoke error\n"); 
       exit(1);
    }
    

    pid_t pid; 

    if ( (pid = fork()) < 0 ) {
        fprintf( stderr, "fork error[%d][%s]\n", errno, strerror(errno)); 
        exit(1);
    } else if ( pid > 0 ) {
        // Parent 
        fprintf( stdout, "My Pid[%d], Child Pid[%d]\n", getpid(), pid);
        sleep(60);
        /*int status;*/
        /*pid_t childpid = waitpid( -1, &status, 0);*/
        /*fprintf( stdout, "Pid[%d] exit \n", childpid) ;*/
    } else {
        // Child 
        fprintf( stdout, "My Pid[%d], Parent Pid[%d]\n", getpid(), getppid() );
        // kill -s 17 <PID> 产生信号时, 子进程执行到sig_handle函数中, 信号处理函数会被子进程继承
        // 具体可以 man sigaction 看到, execev(2) 处理函数将会重置, 但是忽略的依然忽略
        sleep(15);

        sleep(15);
    }


    return 0;
}

void sig_handle ( int signum ) {
    fprintf(stdout, "pid[%d], signal[%d] has been cautht\n", getpid(), signum);
    pid_t pid;
    int status;
    while( (pid = waitpid(-1, &status, 0) ) > 0) {
        fprintf(stdout, "pid %d exited!\n", pid );        
    }
}
