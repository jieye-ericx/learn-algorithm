/* 题目描述
把 M 个同样的苹果放在 N 个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
注意：5、1、1 和 1、5、1 是同一种分法，即顺序无关。
输入描述:
输入包含多组数据。
每组数据包含两个正整数 m和n（1≤m, n≤20）。
输出描述:
对应每组数据，输出一个整数k，表示有k种不同的分法。
示例1
输入
7 3
输出
8 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <list>
using namespace std;
int m, n, dp[22][22];
int main()
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < 22; i++)
	{
		// !注意初始状态
		dp[1][i] = 1;
		dp[i][0] = 1;
	}
	// n       m
	// i个盘子放j个果子
	for (int i = 2; i < 22; i++)
	{
		for (int j = 1; j < 22; j++)
		{
			// dp[i][j - 1]会和dp[i - 1][j]发生重复，只有像下面那样j - i保证i个盘子每个盘子至少有一个
			// 因为对于dp[i][j],只要有一个盘子是空的，就等价于dp[i-1][j];
			// !所以dp[i][j]比dp[i-1][j]多的只是所有盘子都不为空的情况
			// dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] = dp[i - 1][j] + (j >= i ? dp[i][j - i] : 0);
			// 这里的【j-i】中的i相当于多重背包的物品i的质量
		}
	}
	while (scanf("%d%d", &m, &n) != EOF)
	{
		printf("%d\n", dp[n][m]);
	}

	return 0;
}
