/* 题目描述
!与lt518相比，本题求凑成的最少硬币数，那题求总共组合数
    有若干张邮票，要求从中选取最少的邮票张数凑成一个给定的总值。     
    如，有1分，3分，3分，3分，4分五张邮票，要求凑成10分，则使用3张邮票：3分、3分、4分即可。
输入描述:
    有多组数据，对于每组数据，首先是要求凑成的邮票总值M，M<100。
    然后是一个数N，N〈20，表示有N张邮票。接下来是N个正整数，分别表示这N张邮票的面值，且以升序排列。
输出描述:
      对于每组数据，能够凑成总值M的最少邮票张数。若无解，输出0。
示例1
输入
10
5
1 3 3 3 4
输出
3 */
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
int m, n, a[22];
const int MAX = 100000;
int main()
{
    while (scanf("%d", &m) != EOF)
    {
        scanf("%d", &n);
        vector<vector<int>>
            dp(n + 1, vector<int>(m + 1, MAX));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            // dp[i][a[i]] = 1;
        }
        // !很重要，对于这种dp初始不是0的情况来说，需要赋值
        dp[0][0] = 0;
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= m; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // dp[i][j]=表示用i种邮票能表示j面值的最少张数
        for (int i = 1; i <= n; i++)
        {
            // j从0开始可以解决因为dp初始值不是0而dp[i][0]=0的问题
            for (int j = 0; j <= m; j++)
            {
                if (j < a[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - a[i]] + 1);
                }
            }
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= m; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (dp[n][m] < MAX)
            printf("%d\n", dp[n][m]);
        else
            printf("0\n");
    }

    return 0;
}
