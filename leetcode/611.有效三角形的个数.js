/*
 * @lc app=leetcode.cn id=611 lang=javascript
 *
 * [611] 有效三角形的个数
 *
 * https://leetcode-cn.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 65.8K
 * Testcase Example:  '[2,2,3,4]'
 *
 * 给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
 *
 * 示例 1:
 *
 *
 * 输入: [2,2,3,4]
 * 输出: 3
 * 解释:
 * 有效的组合是:
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 *
 *
 * 注意:
 *
 *
 * 数组长度不超过1000。
 * 数组里整数的范围为 [0, 1000]。
 *
 *
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function (nums) {
  let n = nums.length, ans = 0
  nums.sort((a, b) => a - b)
  for (let i = 0; i < n - 2; i++) {
    if (nums[i] === 0) continue
    let k = i
    for (let j = i + 1; j < n - 1; j++) {
      while (k + 1 < n && nums[i] + nums[j] > nums[k + 1]) {
        k++
      }
      // !这种写法每次k都从j+1开始，太浪费了
      // let k
      // for (k = j + 1; k < n; k++) {
      //   if (nums[i] + nums[j] <= nums[k])
      //     break
      // }
      ans += Math.max(k - j, 0);
      console.log(i, j, k, ans);
    }
  }
  return ans
};
//                          0  1  2  3  4  5
console.log(triangleNumber([1, 2, 3, 4, 5, 6]));

// @lc code=end
