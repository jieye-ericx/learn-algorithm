#include<stdio.h>
#include<string>
using namespace std;
char str1[100],str2[100];
int dp[100][100];
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		int L1=strlen(str1);
		int L2=strlen(str2);
		for(int i=0;i<L1;i++)
		{
			for(int j=0;j<L2;j++)
			{
				dp[i][j]=0;
			}
		}
		for( i=0;i<L1;i++)
		{
			for(int j=0;j<L2;j++)
			{
				if(str1[i]==str2[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[L1-1][L2-1]);
	}
	return 0;
}