/* 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
题目数据保证答案符合 32 位带符号整数范围。

示例 1：
  输入：s = "rabbbit", t = "rabbit"
  输出：3
  解释：
  如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
  (上箭头符号 ^ 表示选取的字母)
  rabbbit
  ^^^^ ^^
  rabbbit
  ^^ ^^^^
  rabbbit
  ^^^ ^^^
示例 2：
  输入：s = "babgbag", t = "bag"
  输出：5
  解释：
  如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
  (上箭头符号 ^ 表示选取的字母)
  babgbag
  ^^ ^
  babgbag
  ^^    ^
  babgbag
  ^    ^^
  babgbag
    ^  ^^
  babgbag
      ^^^ */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <list>
using namespace std;

int main()
{

  return 0;
}
int numDistinct(string s, string t)
{
  int n = s.size(), m = t.size();
  s = " " + s;
  t = " " + t;
  // dp[i][j]表示s[1...i],t[1...j]的种数

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++)
  {
    // 空字符串是任何字符串的子序列
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i && j <= m; j++)
    {
      if (s[i] == t[j])
      {
        // dp[i - 1][j - 1]表示将s[i]和t[j]进行绑定
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][m];
}
