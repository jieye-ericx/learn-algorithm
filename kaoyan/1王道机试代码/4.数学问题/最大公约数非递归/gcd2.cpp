#include<stdio.h>
int gcd(int a,int b)
{
	while(b!=0)
	{
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}
void main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",gcd(a,b));	
	}
}