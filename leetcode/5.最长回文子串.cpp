/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
 */

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
string longestPalindrome(string s);
int main()
{
  cout << longestPalindrome("ac") << endl;

  return 0;
}
string longestPalindrome(string s)
{
  int n = s.size();
  string ans = "";
  ans += s[0];
  vector<vector<int>> dp(n, vector<int>(n, true));
  // !使用dp判断s[i-j]是否是回文
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < n; j++)
    {
      dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
      // !虽然理论上i越小j越大越好，但需要判断下新j - i + 1（ans的长度）是否大于现有的
      if (dp[i][j] == 1 && (j - i + 1) >= ans.size())
      {
        // cout << "123123";
        ans = s.substr(i, j - i + 1);
      }
    }
  }
  return ans;
  //! 这样只能知道最长回文长度，不知道具体是什么
  // string ss = s;
  // reverse(s.begin(), s.end());
  // int dp[s.size() + 1][s.size() + 1];
  // memset(dp, 0, sizeof(dp));
  // for (int i = 1; i < s.size() + 1; i++)
  // {
  //   for (int j = 1; j < ss.size() + 1; j++)
  //   {
  //     if (s[i - 1] == ss[j - 1])
  //     {
  //       dp[i][j] = dp[i - 1][j - 1] + 1;
  //     }
  //     else
  //     {
  //       dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  //     }
  //   }
  // }
}