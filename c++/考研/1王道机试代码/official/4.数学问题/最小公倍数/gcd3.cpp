#include<stdio.h>
int gcd(int a,int b)
{
	if(b!=0)return gcd(b,a%b);
	else return a;
}
void main()
{
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		printf("%d\n",x*y/gcd(x,y));
	}
}
