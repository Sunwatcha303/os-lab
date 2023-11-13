/* Program demonstrates the use of kill() */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
int notDone = 1; int cnt = 0;
void mySIGhandler(int sig) {
    signal(SIGALRM,SIG_IGN);
    //breaks infinite loop by reset notDone
    notDone = 0;
    //printf("loop should break\n");
}
int main(void) {
    //install handler
    // signal(SIGALRM,mySIGhandler);
    pid_t pid = fork();
    if (pid == 0) {
        printf("child wait for SIGALRM\n");
        while (1);
        printf("this line should not be show");
    } else {
        sleep(4);
        printf("sending SIGALRM\n");
        kill(getpid(),SIGALRM);
        wait(NULL);
    }
    return 0;
} //main