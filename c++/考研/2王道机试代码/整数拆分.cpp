/* 题目描述
一个整数总可以拆分为2的幂的和，例如： 7=1+2+4 7=1+2+2+2 7=1+1+1+4 7=1+1+1+2+2 
7=1+1+1+1+1+2 7=1+1+1+1+1+1+1 总共有六种不同的拆分方式。 
再比如：4可以拆分成：4 = 4，4 = 1 + 1 + 1 + 1，4 = 2 + 2，4=1+1+2。 
用f(n)表示n的不同拆分的种数，例如f(7)=6. 要求编写程序，读入n(不超过1000000)，输出f(n)%1000000000。
输入描述:
每组输入包括一个整数：N(1<=N<=1000000)。
输出描述:
对于每组数据，输出f(n)%1000000000。
示例1
输入
7
输出
6 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
// !内存占用过多
// int n, base[20], dp[20][1000005];
// int main()
// {
// 	memset(dp, 0, sizeof(dp));

// 	for (int i = 0; i < 20; i++)
// 	{
// 		base[i] = 1 << i;
// 		// cout << i << " " << base[i] << endl;
// 		dp[i][0] = 1;
// 	}
// 	for (int i = 0; i < 1000005; i++)
// 	{
// 		dp[0][i] = 1;
// 	}
// 	for (int i = 1; i < 20; i++)
// 	{
// 		for (int j = 1; j <= 1000000; j++)
// 		{
// 			if (j < base[i])
// 			{
// 				dp[i][j] = dp[i - 1][j];
// 			}
// 			else
// 			{
// 				dp[i][j] = (dp[i - 1][j] + dp[i][j - base[i]]) % 1000000000;
// 			}
// 		}
// 	}
// 	while (scanf("%d", &n) != EOF)
// 	{
// 		printf("%d\n", dp[19][n]);
// 	}

// 	return 0;
// }
int n, base[20], dp[1000005];
int main()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 20; i++)
	{
		base[i] = 1 << i;
	}
	for (int i = 0; i < 1000005; i++)
	{
		dp[i] = 1;
	}
	for (int i = 1; i < 20; i++)
	{
		for (int j = base[i]; j <= 1000000; j++)
		{
			dp[j] += dp[j - base[i]];
			dp[j] %= 1000000000;
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", dp[n]);
	}

	return 0;
}
