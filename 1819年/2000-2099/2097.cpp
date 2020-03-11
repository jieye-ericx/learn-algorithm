#include <stdio.h>

int main(){
	int a,m=0,n=0,o=0,num1=0,num2=0,num3=0;
	while(~scanf("%d",&a),a)
	{
		n=a;m=a;o=a;
		while(n){
			num1+=n%10;
			n/=10;
		}
		while(m){
			num2+=m%12;
			m/=12;
		}
		while(o){
			num3+=o%16;
			o/=16;
		}
		if(num1==num2&&num1==num3)
		printf("%d is a Sky Number.\n",a);
        else
        printf("%d is not a Sky Number.\n",a);
        num1=0;num2=0;num3=0;
	}
	return 0;
} 
