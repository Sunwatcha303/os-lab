#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int main(){
    char userChoice = 'z';
    pid_t pid;
    while(userChoice != 'q'){
        printf("a: ls\n");
        printf("b: ps\n");
        printf("c: whoami\n");
        printf("q: for quit\n");
        scanf(" %c", &userChoice);
        pid = fork();
        if(pid == 0){
            switch(userChoice){
                case 'a':
                    execlp("/bin/ls","ls",NULL);
                case 'b':
                    execlp("/bin/ps","ps",NULL);
                case 'c':
                    execlp("/bin/whoami","whoami",NULL);
            }
            exit(0);
        }
        wait(NULL);
    }
    printf("parent terminated\n");
}