/*
 * @lc app=leetcode.cn id=1893 lang=javascript
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 *
 * https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/
 *
 * algorithms
 * Easy (57.55%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 43.2K
 * Testcase Example:  '[[1,2],[3,4],[5,6]]\n2\n5'
 *
 * 给你一个二维整数数组 ranges 和两个整数 left 和 right 。每个 ranges[i] = [starti, endi] 表示一个从
 * starti 到 endi 的 闭区间 。
 *
 * 如果闭区间 [left, right] 内每个整数都被 ranges 中 至少一个 区间覆盖，那么请你返回 true ，否则返回 false 。
 *
 * 已知区间 ranges[i] = [starti, endi] ，如果整数 x 满足 starti i ，那么我们称整数x 被覆盖了。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
 * 输出：true
 * 解释：2 到 5 的每个整数都被覆盖了：
 * - 2 被第一个区间覆盖。
 * - 3 和 4 被第二个区间覆盖。
 * - 5 被第三个区间覆盖。
 *
 *
 * 示例 2：
 *
 *
 * 输入：ranges = [[1,10],[10,20]], left = 21, right = 21
 * 输出：false
 * 解释：21 没有被任何一个区间覆盖。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1 i i
 * 1
 *
 *
 */

// @lc code=start
/**
 * @param {number[][]} ranges
 * @param {number} left
 * @param {number} right
 * @return {boolean}
 */
var isCovered = function (ranges, left, right) {
  const diff = new Array(52).fill(0); // 差分数组
  // 用差分数组 diff 维护相邻两个整数的被覆盖区间数量变化量
  for (const [l, r] of ranges) {
    diff[l]++;
    diff[r + 1]--;
  }
  // 前缀和
  let curr = 0;
  for (let i = 1; i < 51; i++) {
    curr += diff[i];
    if (left <= i && i <= right && curr <= 0) {
      return false;
    }
  }
  return true;
};

// @lc code=end
