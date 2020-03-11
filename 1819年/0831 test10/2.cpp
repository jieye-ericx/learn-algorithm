#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm> 
using namespace std;
int dp[100001][12];//一开始数组开到11 WA了好几遍
int maxn(int a,int b,int c)
{
	int max1;
	max1=a>b?a:b;
	max1=max1>c?max1:c;
	return max1;
}
int main()
{
	int n,x,t;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int i,j,m=0;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&t);
			dp[t][x]++;
			if(t>m)
			m=t;
		}
		for(i=m-1;i>=0;i--)
		{
			//dp[i][0] += max(dp[i+1][0],dp[i+1][1]); 
			for(j=0;j<=10;j++)
			dp[i][j]+=maxn(dp[i+1][j+1],dp[i+1][j],dp[i+1][j-1]);//从三个方向寻找最大权值的方向
		} 
		printf("%d\n",dp[0][5]);
	}
	return 0;
}
