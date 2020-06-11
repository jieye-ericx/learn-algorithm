#include <stdio.h>
int main(){
	int n,num1,num2;
	scanf("%d",&n);
	while(n){
		scanf("%d%d",&num1,&num2);
		int sum=(num1%100+num2%100)%100;
		printf("%d\n",sum);
		n--;
	}
	return 0; 
}
