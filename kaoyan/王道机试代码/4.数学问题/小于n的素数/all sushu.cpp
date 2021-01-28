#include<stdio.h>
int prime[100001];
int primeSize;
bool mark[100001];
void init()
{
	for(int i=0;i<100001;i++)mark[i]=false;
	for(i=2;i<100001;i++)
	{
		if(mark[i]==true)continue;
		for(int j=i*i;j<100001;j+=i)
		{
			mark[j]=true;
		}
	}
	primeSize=0;
	for(i=2;i<100001;i++)
	{
		if(mark[i]==false)prime[primeSize++]=i;
	}
}
void main()
{
	init();
	int n;
	bool isFirst=true;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<primeSize&&prime[i]<n;i++)
		{
			if(prime[i]%10==1)
			{
				if(isFirst==true)
				{
					printf("%d",prime[i]);
					isFirst=false;
				}
				else printf(" %d",prime[i]);
			}
		}
		if(isFirst==false)
		{
			isFirst=true;
			printf("\n");
		}
		else printf("-1\n");
	}
}