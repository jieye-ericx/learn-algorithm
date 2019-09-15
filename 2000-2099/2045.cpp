#include <stdio.h>
int main(){
	long long int a[51]={0};
	a[1]=3;a[2]=6;a[3]=6;
	for(int i=4;i<51;i++)
	a[i]=a[i-1]+2*a[i-2];
	int n;
	while(scanf("%d",&n)!=-1&&n)
		printf("%lld\n",a[n]);
}
