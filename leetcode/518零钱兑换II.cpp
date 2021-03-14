/* 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。
https://leetcode-cn.com/problems/coin-change-2/ 
示例 1:
输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
示例 2:
输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。
示例 3:
输入: amount = 10, coins = [10] 
输出: 1 */
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
int main()
{

    return 0;
}

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        if (coins.size() == 0)
            return 0;
        // ?特殊情况
        int n = coins.size();
        coins.push_back(0);
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        dp[1][coins[1]] = 1;
        // !问题出在初始值这一块
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (i == 1 && j == 1)
                    continue;
                if (j < coins[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    // !dp[i][j]表示用前i种coin能凑出j元的方案数，dp[i][0]不应该是0；
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i]]);
                    if (j - coins[i] == 0)
                        dp[i][j]++;
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][amount];
    }
};