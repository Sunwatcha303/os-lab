#include <stdio.h>
int main(){
	int cnt = 1;
	int input = 0;
	float sum = 0;
	printf("input number : ");
	scanf("%d",&input);
	while(input > 0){
		sum += input;
		printf("input number : ");
		scanf("%d",&input);
		cnt++;
	}
	if(sum != 0) cnt--;
	float result = sum/cnt;
	printf("sum : %.f, avg : %.2f\n",sum,result);
	return 0;
}
