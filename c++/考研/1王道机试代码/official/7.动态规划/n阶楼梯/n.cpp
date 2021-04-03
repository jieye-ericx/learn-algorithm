#include<stdio.h>
__int64 F(int n)
{
	if(n==1)return 1;
	if(n==2)return 2;
	else return F(n-1)+F(n-2);
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