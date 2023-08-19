#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int csum;
void *cThread(void *param);

int main(int argc, char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, cThread, argv[1]);
    
    int msum = 0;
    int upper = atoi(argv[1]);
    for(int i=1;i<=upper;i++){
        // sleep(0.009);
        msum+=i;
        // printf("%d\n",csum);
    }
    pthread_join(tid,NULL);

    printf("difference csum and msum: %d\n",csum-msum);
    // printf("csum: %d\n",csum);
    // printf("msum: %d\n",msum);
    return 0;    
}

void *cThread(void *param){
    int upper = atoi(param);
    csum = 0;
    for(int i=1;i<=2*upper;i++){
        // sleep(0.001);
        csum+=i;
    }
    // csum = (2*upper)*((2*upper)+1)/2;
    pthread_exit(0);
}