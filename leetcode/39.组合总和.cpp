/********
39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
转换后输入
4 7
2 3 6 7

示例 2:
输入: candidates = [2,3,5], target = 8,
3 8
2 3 5
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
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
int combinationSum(vector<int> &candidates, int target);
int main()
{
  vector<int> a;
  int num, t, tar;
  cin >> num >> tar;
  while (num--)
  {
    cin >> t;
    a.push_back(t);
  }
  combinationSum(a, tar);
  return 0;
}

int combinationSum(vector<int> &candidates, int target)
{
  int dp[target + 1];
  memset(dp, 0, sizeof(dp));
  sort(candidates.begin(), candidates.end());
  dp[candidates[0]] = 1;
  //我发现这种题动态规划好像做不出所有的解，只能得出是否存在解或者解的数量
  // 目前主要需要提升动态规划能力，所以这里尝试先算出数量
  // 用一个一位数组dp，dp[x]表示在目标为x时的解的数量
  // 那么dp[x]应该为dp[x-candidates[0~size-1]]的和
  // !20230307 这是个错误的518的解法，这是求排列数，1，2和2，1会被当成不同的解法
  for (int j = 1; j <= target; j++)
  {
    for (int i = 0; i < candidates.size(); i++)
    {
      // for (int k = 0; k * candidates[i] <= j; k++)
      // {
      //     dp[i + 1][j] = max(dp[i - 1][j], dp[i - 1][j - k * candidates[i]] + k * candidates[i]);
      // }
      if (j >= candidates[i])
        dp[j] += dp[j - candidates[i]];
    }
  }
  for (int i = 1; i < target + 1; i++)
  {
    cout << dp[i] << " ";
  }
  return 1;
}