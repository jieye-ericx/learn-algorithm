/*
300
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

!示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
!示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4
!示例 3：
输入：nums = [7,7,7,7,7,7,7]
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
int lengthOfLIS(vector<int> &nums)
{
  /*
  !考虑到访问nums[i]时,有两种可能,加入最长严格递增子序列或不加入
  !dp[i][0]表示nums[i]加入,dp[i][1]表示不加入
  !加入:则此时dp[i][0]=max(dp[i-1][0]+1,dp[i-1][1]+1);
  !不加入:则此时dp[i][1]=max(dp[i-1][0],dp[i-1][1]);

  对于[1 8 9] [2 3 4 5 6 7] 10 11,如何让状态方程选择第二个[]里的方案呢
  !得增加一种可能,即从nums[i]重新开始,我的思路断了,下面是答案
   */
  /* https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
   定义dp[i] 为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度，注意 nums[i] 必须被选取。
我们从小到大计算dp 数组的值，在计算dp[i]之前，我们已经计算出dp[0…i−1]的值，则状态转移方程为：
dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]
即考虑往dp[0…i−1]中最长的上升子序列后面再加一个nums[i]。由于dp[j] 代表nums[0…j]中以nums[j]结尾的最长上升子序列，所
以如果能从dp[j] 这个状态转移过来，那么nums[i] 必然要大于nums[j]，才能将nums[i] 放在nums[j] 后面以形成更长的上升子序列。

最后，整个数组的最长上升子序列即所有dp[i] 中的最大值。
length=max(dp[i]),其中0≤i<n
   */
  int n = nums.size();
  int dp[n], ans = 1;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 1; i < n; i++)
  {
    dp[i] = 1; //!这个初始化挺重要
    for (int j = 0; j < i; j++)
    {
      if (nums[j] < nums[i])
      {
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(dp[i], ans);
      }
    }
  }
  return ans;
}