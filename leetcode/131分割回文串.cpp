/* 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串
示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：
输入：s = "a"
输出：[["a"]]
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
int main()
{

  return 0;
}
class Solution
{
private:
  vector<vector<int>> f;
  vector<vector<string>> ret;
  vector<string> ans;
  int n;

public:
  void dfs(const string &s, int i)
  {
    if (i == n)
    {
      ret.push_back(ans);
      return;
    }
    for (int j = i; j < n; ++j)
    {
      if (f[i][j])
      {
        ans.push_back(s.substr(i, j - i + 1));
        dfs(s, j + 1);
        ans.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s)
  {
    n = s.size();
    f.assign(n, vector<int>(n, true));
    // !使用dp判断s[i-j]是否是回文
    for (int i = n - 1; i >= 0; --i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
      }
    }

    dfs(s, 0);
    return ret;
  }
};
