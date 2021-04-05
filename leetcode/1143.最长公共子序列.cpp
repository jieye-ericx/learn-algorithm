#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int longestCommonSubsequence(string t1, string t2)
{
  int dp[t1.size() + 1][t2.size() + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < t1.size() + 1; i++)
  {
    for (int j = 1; j < t2.size() + 1; j++)
    {
      if (t1[i - 1] == t2[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[t1.size()][t2.size()];
}
int main()
{
  return 0;
}
