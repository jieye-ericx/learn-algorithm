/*
 * @lc app=leetcode.cn id=718 lang=golang
 *
 * [718] 最长重复子数组
 *
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (57.11%)
 * Likes:    864
 * Dislikes: 0
 * Total Accepted:    173.4K
 * Total Submissions: 303.9K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * 输出：3
 * 解释：长度最长的公共子数组是 [3,2,1] 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 100
 *
 *
 */

// @lc code=start
func findLength(nums1 []int, nums2 []int) (ans int) {
	ans = -0xffffff
	dp := make([][]int, len(nums1)+1)
	for i := 0; i < len(nums1)+1; i++ {
		dp[i] = make([]int, len(nums2)+1)
	}
	for i := 1; i < len(nums1)+1; i++ {
		for j := 1; j < len(nums2)+1; j++ {
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = 0
			}
		}
	}
	for i := 0; i < len(nums1)+1; i++ {
		for j := 0; j < len(nums2)+1; j++ {
			ans = max(ans, dp[i][j])
		}
	}
	return ans
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
