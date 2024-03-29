/* 题目描述
辰辰是个很有潜能、天资聪颖的孩子，他的梦想是称为世界上最伟大的医师。 
为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。 
医师把他带到个到处都是草药的山洞里对他说： “孩子，这个山洞里有一些不同的草药，
采每一株都需要一些时间，每一株也有它自身的价值。 我会给你一段时间，在这段时间里，
你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。” 如果你是辰辰，你能完成这个任务吗？
输入描述:
输入的第一行有两个整数T（1 <= T <= 1000）和M（1 <= M <= 100），T代表总共能够用来采药的时间，M代表山洞里的草药的数目。
接下来的M行每行包括两个在1到100之间（包括1和100）的的整数，分别表示采摘某株草药的时间和这株草药的价值。
输出描述:
可能有多组测试数据，对于每组数据，
输出只包括一行，这一行只包含一个整数，表示在规定的时间内，可以采到的草药的最大总价值。
示例1
输入
复制
70 3
71 100
69 1
1 2
输出
复制
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
int t, m, a[102][2];
int main()
{
    while (scanf("%d%d", &t, &m) != EOF)
    {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a[i][0], &a[i][1]);
        }
        vector<
            vector<int>

            >
            dp(m + 1, vector<int>(t + 1, 0));
        // !考虑初始情况，dp[i][j]，i=0时表示一道菜都不选，dp[0][j]=0;
        // !同理dp[i][0]=0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= t; j++)
            {
                // 如果当前的钱j大于菜品i的价格
                // !选择当前产品或不选
                if (j >= a[i][0]) //注意这里是a[i][0]
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i][0]] + a[i][1]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j <= t; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        printf("%d\n", dp[m][t]);
    }

    return 0;
}
