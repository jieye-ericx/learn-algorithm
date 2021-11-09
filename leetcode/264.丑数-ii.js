/*
 * @lc app=leetcode.cn id=264 lang=javascript
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (57.34%)
 * Likes:    714
 * Dislikes: 0
 * Total Accepted:    91.3K
 * Total Submissions: 158.7K
 * Testcase Example:  '10'
 *
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 *
 * 丑数 就是只包含质因数 2、3 和/或 5 的正整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 10
 * 输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：1
 * 解释：1 通常被视为丑数。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function (n) {
  let ans = Array(n + 1).fill(1);
  ans[1] = 1;
  let p2 = 1, p3 = 1, p5 = 1, i = 2;
  while (i <= n) {
    ans[i] = Math.min(ans[p2] * 2, Math.min(ans[p3] * 3, ans[p5] * 5));
    if (ans[p2] * 2 == ans[i]) p2++;
    if (ans[p3] * 3 == ans[i]) p3++;
    if (ans[p5] * 5 == ans[i]) p5++;
    i++
  }
  return ans[n]
};
// @lc code=end
