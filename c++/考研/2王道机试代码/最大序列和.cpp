/* 题目描述
给出一个整数序列S，其中有N个数，定义其中一个非空连续子序列T中所有数的和为T的“序列和”。 对于S的所有非空连续子序列T，求最大的序列和。 变量条件：N为正整数，N≤1000000，结果序列和在范围（-2^63,2^63-1）以内。
输入描述:
第一行为一个正整数N，第二行为N个整数，表示序列中的数。
输出描述:
输入可能包括多组数据，对于每一组输入数据，
仅输出一个数，表示最大序列和。
示例1
输入
5
1 5 -3 2 4

6
1 -2 3 4 -10 6

4
-3 -1 -2 -5
输出
9
7
-1 */

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
int n;
long long dp[1000004], a[1000004], ans;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        dp[0] = a[0];
        ans = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(a[i], dp[i - 1] + a[i]);
            ans = max(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
