#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    int i = 0;
    int num;
    int sum = 0;
    printf("Enter a positive number : ");
    scanf("%d",&num);
    if(num <= 0){
	    printf("You did not enter a positive number\n");
	    exit(1);
    }
    if(pid = fork() > 0){
	    for(int i=0;i<=num;i++){
		    sum+=i;
	    }
    } else{
	    for(int i=0;i<=2*num;i++){
		    sum+=i;
	    }
	    printf("I am child my sum = %d\n",sum);
	    exit(0);
    }
    wait(NULL);
    printf("I am parent my sum = %d\n", sum);
    return 0;

}
