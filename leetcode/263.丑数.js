/*
 * @lc app=leetcode.cn id=263 lang=javascript
 *
 * [263] 丑数
 *
 * https://leetcode.cn/problems/ugly-number/description/
 *
 * algorithms
 * Easy (50.73%)
 * Likes:    380
 * Dislikes: 0
 * Total Accepted:    149.8K
 * Total Submissions: 295.5K
 * Testcase Example:  '6'
 *
 * 丑数 就是只包含质因数 2、3 和 5 的正整数。
 *
 * 给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 6
 * 输出：true
 * 解释：6 = 2 × 3
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：true
 * 解释：1 没有质因数，因此它的全部质因数是 {2, 3, 5} 的空集。习惯上将其视作第一个丑数。
 *
 * 示例 3：
 *
 *
 * 输入：n = 14
 * 输出：false
 * 解释：14 不是丑数，因为它包含了另外一个质因数 7 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
var isUgly = function (num) {
  if (num <= 0) return false;
  if (num === 1) return true;
  let ans = Array(num + 1);
  ans[1] = 1;
  let p2 = 1,
    p3 = 1,
    p5 = 1;
  for (let i = 2; ; i++) {
    ans[i] = Math.min(ans[p2] * 2, Math.min(ans[p3] * 3, ans[p5] * 5));
    if (ans[i] === num) return true;
    else if (ans[i] > num) return false;
    if (ans[p2] * 2 == ans[i]) p2++;
    if (ans[p3] * 3 == ans[i]) p3++;
    if (ans[p5] * 5 == ans[i]) p5++;
  }
};
// @lc code=end
