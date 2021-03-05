/* 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
注意：不允许旋转信封。

示例 1：
输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出：3
解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
示例 2：
输入：envelopes = [[1,1],[1,1],[1,1]]
输出：1
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

int maxEnvelopes(vector<vector<int>> &envelopes)
{
  if (envelopes.empty())
  {
    return 0;
  }
  /* 先对一边排序,这样就变成了最长严格递增子序列问题
  https://leetcode-cn.com/problems/russian-doll-envelopes/solution/e-luo-si-tao-wa-xin-feng-wen-ti-by-leetc-wj68/
   */
  sort(envelopes.begin(), envelopes.end(), tmp);
  int n = envelopes.size();
  for (int i = 0; i < n; i++)
  {
    cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
  }
  vector<int> dp(n, 1);
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (envelopes[j][1] < envelopes[i][1])
      {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  return *max_element(dp.begin(), dp.end());
}

static bool tmp(vector<int> p1, vector<int> p2)
{
  if (p1[0] != p2[0])
    return p1[0] < p2[0];
  else
    return p1[1] > p2[1];
}
