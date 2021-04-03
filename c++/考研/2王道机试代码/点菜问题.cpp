/* 
题目描述
    北大网络实验室经常有活动需要叫外卖，但是每次叫外卖的报销经费的总额最大为C元，有N种菜可以点，经过长时间的点菜，
    网络实验室对于每种菜i都有一个量化的评价分数（表示这个菜可口程度），为Vi，每种菜的价格为Pi, 
    问如何选择各种菜，使得在报销额度范围内能使点到的菜的总评价分数最大。     
    注意：由于需要营养多样化，每种菜只能点一次。
输入描述:
    输入的第一行有两个整数C（1 <= C <= 1000）和N（1 <= N <= 100），C代表总共能够报销的额度，
    N>代表能点菜的数目。接下来的N行每行包括两个在1到100之间（包括1和100）的的整数，分别表示菜的价格和菜的评价分数。
输出描述:
    输出只包括一行，这一行只包含一个整数，表示在报销额度范围内，所点的菜得到的最大评价分数。
示例1
输入
9 4
2 25
3 20
4 50
1 18
40 2
25 30
10 8
输出
95
38
 */
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
int c, n, a[102][2];
int main()
{
    while (scanf("%d%d", &c, &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i][0], &a[i][1]);
        }
        vector<
            vector<int>

            >
            dp(n + 1, vector<int>(c + 1, 0));
        // !考虑初始情况，dp[i][j]，i=0时表示一道菜都不选，dp[0][j]=0;
        // !同理dp[i][0]=0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= c; j++)
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
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= c; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        printf("%d\n", dp[n][c]);
    }

    return 0;
}
