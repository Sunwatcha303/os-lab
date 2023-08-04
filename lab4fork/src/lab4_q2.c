#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(void){
	pid_t pid;
	int i;

	pid = fork();
	if(pid <0) exit(-1);

	if(pid > 0){
		i = 1;
		printf("my copy of i is %d\n",i);
	} else {
		i = 2;
		printf("my copy of i is %d\n",i);
	}

	wait(NULL);
	return 0;
}
