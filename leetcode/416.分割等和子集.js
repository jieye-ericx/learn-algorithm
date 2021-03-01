/**
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
 
示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.
 */
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
  let sum = nums.reduce((pri, cur) => pri + cur, 0),
    dp = []
  if (sum % 2 === 1) return false
  sum /= 2
  for (let i = 0; i <= nums.length; i++) {
    dp.push(Array(sum + 1).fill(0))
  }
  //   console.log(dp)

  for (let i = 1; i < nums.length; i++) {
    for (let j = nums[i - 1]; j <= sum; j++) {
      dp[i][j] = Math.max(
        dp[i - 1][j],
        dp[i - 1][j - nums[i - 1]] + nums[i - 1]
      )
    }
  }
  //   console.log(dp)
  return dp[nums.length - 1][sum] === sum
}

// console.log(canPartition([1, 5, 11, 5]))
//优化
var canPartition = function (nums) {
  let sum = nums.reduce((pri, cur) => pri + cur, 0)
  if (sum % 2 === 1) return false
  sum /= 2
  let dp = Array(sum + 1).fill(0)

  for (let i = 0; i < nums.length; i++) {
    for (let j = sum; j >= nums[i]; j--) {
      dp[j] = Math.max(dp[j], dp[j - nums[i]] + nums[i])
    }
  }
  //   console.log(dp)
  return dp[sum] === sum
}
console.log(canPartition2([1, 5, 11, 5]))
