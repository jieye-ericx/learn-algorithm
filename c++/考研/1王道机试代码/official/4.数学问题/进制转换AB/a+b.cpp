#include<stdio.h>
void main()
{
	int n;
	__int64 a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		scanf("%I64d%I64d",&a,&b);
		a+=b;
		__int64 ans[100];
		int size=0;
		do
		{
			ans[size++]=a%n;
			a/=n;
		}while(a!=0);
		for(int i=size-1;i>=0;i--)
		{
			printf("%d",ans[i]);
		}
		printf("\n");
	}
}