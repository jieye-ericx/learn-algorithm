#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int main()
{

    return 0;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int dp[n][n], ans = 0xfffffff;
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}
//!只用一位数组
int minimumTotal2(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int dp[n], ans = 0xfffffff;
    dp[0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        // for (int i = 0; i < n; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        dp[i] = dp[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; j--)
        {
            dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
        }
        dp[0] = dp[0] + triangle[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[i]);
    }
    return ans;
}

/*0 1 2 3
0 2
1 3 4
2 6 5 7
3 4 1 8 3
 */