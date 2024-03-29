/*
 * @lc app=leetcode.cn id=34 lang=javascript
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.52%)
 * Likes:    1107
 * Dislikes: 0
 * Total Accepted:    286K
 * Total Submissions: 672.3K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 进阶：
 *
 *
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 *
 *
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {

  let binarySearch = (arr, le, ri, target) => {
    let lee = le, rii = ri
    while (lee <= rii) {
      const mid = Math.floor((lee + rii) / 2)
      if (target > arr[mid]) {
        lee = mid + 1
      } else if (target < arr[mid]) {
        rii = mid - 1
      } else {
        return mid
      }
    }
  }

  let targetIndex = binarySearch(nums, 0, nums.length - 1, target), ans = 1
  if (targetIndex === undefined) return [-1, - 1]
  let i = targetIndex, j = targetIndex
  for (; nums[i] === target; i--) {
  }
  for (; nums[j] === target; j++) {
  }
  return [i + 1, j - 1]
};
console.log(searchRange([1], 1))

// @lc code=end

