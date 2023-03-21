/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode.cn/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (43.10%)
 * Likes:    1959
 * Dislikes: 0
 * Total Accepted:    342.3K
 * Total Submissions: 794K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 * 测试用例的答案是一个 32-位 整数。
 *
 * 子数组 是数组的连续子序列。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * nums 的任何前缀或后缀的乘积都 保证 是一个 32-位 整数
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int dp[nums.size()], ans = nums[0];
        int dp1[nums.size()];
        dp[0] = nums[0];
        dp1[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] * nums[i], max(nums[i], dp1[i - 1] * nums[i]));
            dp1[i] = min(dp1[i - 1] * nums[i], min(nums[i], dp[i - 1] * nums[i]));
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

// int main()
// {
//     vector<int> a(9);
//     a[0] = -2;
//     a[1] = 1;
//     a[2] = -3;
//     a[3] = 4;
//     a[4] = -1;
//     a[5] = 2;
//     a[6] = 1;
//     a[7] = -5;
//     a[8] = 4;
//     cout << maxSubArray(a);
//     return 0;
// }
// @lc code=end
