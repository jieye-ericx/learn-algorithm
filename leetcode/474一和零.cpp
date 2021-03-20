/* 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
示例 2：

输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
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

int findMaxForm(vector<string> &strs, int m, int n)
{
  int n = strs.size();
  int dp[m + 1][n + 1];
  memset(dp, 0, sizeof(dp));

  for (auto s : strs)
  {
    int *count = countzeroesones(s);
    for (int zeroes = m; zeroes >= count[0]; zeroes--)
      for (int ones = n; ones >= count[1]; ones--)
        dp[zeroes][ones] = max(1 + dp[zeroes - count[0]][ones - count[1]], dp[zeroes][ones]);
  }
  return dp[m][n];
}

int *countzeroesones(string s)
{
  int c[2];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < s.length(); i++)
  {
    c[s[i] - '0']++;
  }
  return c;
}
