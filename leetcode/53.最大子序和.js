/*
 * @lc app=leetcode.cn id=53 lang=javascript
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (54.55%)
 * Likes:    3429
 * Dislikes: 0
 * Total Accepted:    570.3K
 * Total Submissions: 1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0]
 * 输出：0
 *
 *
 * 示例 4：
 *
 *
 * 输入：nums = [-1]
 * 输出：-1
 *
 *
 * 示例 5：
 *
 *
 * 输入：nums = [-100000]
 * 输出：-100000
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10^5
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 *
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
  let ans = new Array(nums.length).fill(0), res
  // !ans[i]表示以nums[i]结尾的子数组的最大和
  res = ans[0] = nums[0]
  for (let i = 1; i < nums.length; i++) {
    const element = nums[i];
    ans[i] = Math.max(ans[i - 1] + nums[i], nums[i])
    res = Math.max(res, ans[i])
  }
  return res
};
// @lc code=end

