#include<stdio.h>
int prime[1001];
int primeSize;
bool mark[1001];
void init()
{
	primeSize=0;
	for(int i=0;i<1001;i++)mark[i]=false;
	for(i=2;i<1001;i++)
	{
		if(mark[i]==true)continue;
		prime[primeSize++]=i;
		//if(i>=100)continue;
		for(int j=i*i;j<1001;j+=i)
		{
			mark[j]=true;
		}
	}
}
void main()
{
	int cnt[1001],cnt2[1001];
	int n,a;
	init();
	while(scanf("%d%d",&n,&a)==2)
	{
		for(int i=0;i<primeSize;i++)
		{
			cnt[i]=cnt2[i]=0;
		}
		for(i=0;i<primeSize;i++)
		{
			int t=n;
			while(t)
			{
				cnt[i]+=t/prime[i];
				t/=prime[i];
			}
		}
		int ans=123123123;
		for(i=0;i<primeSize;i++)
		{
			while(a%prime[i]==0)
			{
				cnt2[i]++;
				a/=prime[i];
			}
			if(cnt2[i]==0)continue;
			if(cnt[i]/cnt2[i]<ans)ans=cnt[i]/cnt2[i];
	
		}
		printf("%d",ans);
	}
}