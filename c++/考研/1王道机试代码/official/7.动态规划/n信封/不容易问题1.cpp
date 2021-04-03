#include<stdio.h>
__int64 F(int n)
{
	if(n==1)return 0;
	if(n==2)return 1;
	else return (n-1)*(F(n-1)+F(n-2));
}
int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		printf("%I64d\n",F(num));
	}
	return 0;
}