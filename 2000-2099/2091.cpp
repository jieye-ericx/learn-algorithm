#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	char a;
	int n,cnt0=0;
	while(~scanf("%c",&a)&&a!='@'&&~scanf("%d",&n)){
		if(cnt0!=0)printf("\n");
		int m=n,i=2*n-1,t1=n,t2=n,cnt=0;
		while((m--)-1){
			while(cnt++<t2){
				if(cnt==t2||cnt==t1)
				{
					printf("%c",a);
				}
				else
				printf(" ");
				
			}
			t1--;t2++;
			cnt=0;
			printf("\n");
		}
		while(i--)printf("%c",a);
		printf("\n");
		cin.get();
		cnt0++;
	}
	return 0;
}
