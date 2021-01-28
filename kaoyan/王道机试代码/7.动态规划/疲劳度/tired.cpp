#include<stdio.h>
#include<algorithm>
using namespace std;
#define INF 0x7fffffff
int main()
{
	int n,k;
	int list[100];
	int dp[100][100];
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
		}
		for(i=0;i<=n;i++)dp[0][i]=0;//注意i=0,否则dp[i-1][j-2]取不到dp[0][0]
		for(i=1;i<=k;i++)
		{
			for(int j=2*i;j<=n;j++)
			{
				if(j>2*i)dp[i][j]=dp[i][j-1];
				else dp[i][j]=INF;
				if(dp[i][j]>dp[i-1][j-2]+(list[j]-list[j-1])*(list[j]-list[j-1]))
					dp[i][j]=dp[i-1][j-2]+(list[j]-list[j-1])*(list[j]-list[j-1]);
			}
		}
		printf("%d\n",dp[k][n]);
	}
	return 0;
}