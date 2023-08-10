#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int main(){
    pid_t cpid;
    pid_t gcpid;

    cpid = fork();
    if( cpid == 0){
        gcpid = fork();
        if(gcpid ==0){
            printf("Can you see this3?\n");
            exit(0);
        }
        execlp("/bin/123ls","ls",NULL); /*A*/
        printf("can you see this2?\n"); /*B*/
    }
    else{
        printf("can you see this1?\n"); /*C*/
        wait(NULL);
        printf("received Child Complete\n");
        exit(0);
    }
    return 0;
}