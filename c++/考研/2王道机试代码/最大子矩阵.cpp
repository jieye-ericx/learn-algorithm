/* 
题目描述
已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。 
比如，如下4 * 4的矩阵 0 -2 -7 0 9 2 -6 2 -4 1 -4 1 -1 8 0 -2 
的最大子矩阵是 9 2 -4 1 -1 8 这个子矩阵的大小是15。
输入描述:
输入是一个N * N的矩阵。输入的第一行给出N (0 < N <= 100)。
再后面的若干行中，依次（首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……）
给出矩阵中的N2个整数，整数之间由空白字符分隔（空格或者空行）。
已知矩阵中整数的范围都在[-127, 127]。
输出描述:
测试数据可能有多组，对于每组测试数据，输出最大子矩阵的大小。
示例1
输入
4
0 -2 -7 0
9 2 -6 2
-4 1 -4  1
-1 8  0 -2
输出
15 */
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
int n, a[102][102], dp[102][102], help[102][102], arr[102];
//算某一行的最大子序列
int maxSeq()
{
    int dp[n], ans;
    memset(dp, 0, sizeof(dp));
    dp[0] = arr[0];
    ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}
int maxM()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // 下面这个嵌套循环
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == 0)
                {
                    arr[k] = help[j][k];
                }
                else
                {
                    arr[k] = help[j][k] - help[i - 1][k];
                }
            }
            ans = max(ans, maxSeq());
        }
    }
    return ans;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                    help[i][j] = a[i][j];
                else
                {
                    help[i][j] = help[i - 1][j] + a[i][j];
                }
            }
        }
        printf("%d\n", maxM());
        // 错误写法555
        // dp[0][0] = a[0][0];
        // // !第0行单独处理
        // for (int i = 1; i < n; i++)
        // {
        //     dp[0][i] = max(dp[0][i - 1] + a[0][i], a[0][i]);
        // }
        // for (int i = 1; i < n; i++)
        // {
        //     // !每一行（从第一行开始）的第0列单独处理
        //     dp[i][0] = max(dp[i - 1][0] + a[i][0], a[i][0]);
        //     for (int j = 1; j < n; j++)
        //     {
        //         dp[i][j] = max();
        //     }
        //     cout << "\n";
        // }
    }

    return 0;
}
