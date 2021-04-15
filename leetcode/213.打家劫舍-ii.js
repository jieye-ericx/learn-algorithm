/*
 * @lc app=leetcode.cn id=213 lang=javascript
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (41.38%)
 * Likes:    637
 * Dislikes: 0
 * Total Accepted:    113.7K
 * Total Submissions: 268.5K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
  let n = nums.length
  if (n === 0) return 0
  if (n === 1) return nums[0]
  if (n === 2) return Math.max(nums[0], nums[1])

  // !dp[i]代表经过第i家时的最大收益,其实第一个房屋和第二个不能一起偷
  // !只要运行两次就行了,dp[0] = nums[0], dp[1] = nums[1]我原来写的这个犯了个大错误，
  // !既然dp[i]代表经过第i家时的最大收益，那么dp[1]应该是nums[0]和[1]中的较大者啊！！
  let range = (st, ed) => {
    let first = nums[st], sec = Math.max(first, nums[st + 1])
    let ans = Math.max(first, sec)
    for (let i = st + 2; i <= ed; i++) {
      let tmp = sec
      sec = Math.max(nums[i] + first, sec)
      first = tmp
      ans = Math.max(sec, ans)
    }
    return ans
  }
  // 偷第一间
  return Math.max(range(0, n - 2), range(1, n - 1))
};

console.log(rob([100, 3, 1, 3, 1]));
// @lc code=end

