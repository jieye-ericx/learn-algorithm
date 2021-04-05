// https: //leetcode-cn.com/problems/maximal-square/
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
int main()
{

  return 0;
}
class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int m = matrix.size();
    if (m == 0)
      return 0;
    int n = matrix[0].size(), ans = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    /*
    ! dp[i][j]表示在0-i,0-j的子矩阵内包括(i,j)在内的最大正方形面积 
    ! 若matrix[i][j]!=1,则dp[i][j]=0;
     */
    for (int i = 0; i < m; i++)
      if (matrix[i][0] == 49)
      {
        dp[i][0] = 1;
        ans = 1;
      }
    for (int i = 0; i < n; i++)
      if (matrix[0][i] == 49)
      {
        dp[0][i] = 1;
        ans = 1;
      }
    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j < n; j++)
      {
        if (matrix[i][j] == 49)
        {
          dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
          // cout << i << " " << j << " " << dp[i][j] << endl;
          ans = max(ans, dp[i][j]);
        }
      }
    }
    return ans * ans;
  }
};