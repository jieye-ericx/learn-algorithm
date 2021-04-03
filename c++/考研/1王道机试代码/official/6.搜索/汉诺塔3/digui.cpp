#include<stdio.h>
//#include<string.h>
__int64 F(int n)
{
	if(n==1)return 2;
	else return 3*F(n-1)+2;
}
int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		printf("%lld\n",F(num));
	}
	return 0;
}
