#include<stdio.h>
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int n;
	int dp[100];
	int list[100];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&list[i]);
			dp[i]=1;
		}
		int tmp;
		for(i=0;i<n;i++)
		{
			tmp=1;
			for(int j=0;j<i;j++)
			{
				if(list[i]<=list[j])
				{
					tmp=max(tmp,dp[j]+1);
				}
			}
			dp[i]=tmp;
		}
		printf("%d\n",dp[n-1]);
	}
	return 0;
}