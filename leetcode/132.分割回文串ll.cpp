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
/* 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
返回符合要求的 最少分割次数 
示例 1：
输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 */
class Solution
{
private:
  vector<int> dp;
  vector<vector<int>> f;
  int n;

public:
  int minCut(string s)
  {
    n = s.size();
    dp = vector<int>(n + 1, 1 << 30);
    f.assign(n, vector<int>(n, true));

    // !先利用dp预处理出整个s[i...j]是否是回文
    for (int i = n - 1; i >= 0; --i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (f[0][i] == 1)
      {
        dp[i] = 0;
      }
      else
        for (int j = 1; j <= i; j++)
        {
          if (f[j][i] == 1)
          {
            dp[i] = min(dp[j - 1] + 1, dp[i]);
          }
        }
    }
    return dp[n - 1];
  }
};
