#include<stdio.h>
int prime[100001];
int primeSize;
bool mark[100001];
void init()
{
	primeSize=0;
	for(int i=0;i<100001;i++)mark[i]=false;
	for(i=2;i<100001;i++)
	{
		if(mark[i]==true)continue;
		prime[primeSize++]=i;
		if(i>=1000)continue;
		for(int j=i*i;j<100001;j+=i)
		{
			mark[j]=true;
		}
	}
}
int main()
{
	init();
	int n=2;
	while(scanf("%d",&n)!=EOF)
	{
		int ans=0;
		for(int i=0;i<primeSize;i++)
		{
			if(n==1)break;
			else if(n%prime[i]==0)
			{
				while(n%prime[i]==0)
				{
					ans++;
					n/=prime[i];
				}
			}
			else continue;
		}
		printf("%d\n",ans);
	}
	return 0;
}