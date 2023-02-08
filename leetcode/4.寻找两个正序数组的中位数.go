/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.61%)
 * Likes:    6238
 * Dislikes: 0
 * Total Accepted:    881.4K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
package main

import "fmt"

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	i, j, k := 0, 0, 0
	l1, l2 := len(nums1), len(nums2)
	println(l1, l2)
	s := make([]int, l1+l2)
	for ; i < l1 && j < l2; k++ {
		fmt.Println(i, j, s)
		if nums1[i] <= nums2[j] {
			s[k] = nums1[i]
			i++
		} else {
			s[k] = nums2[j]
			j++
		}
	}
	if i != l1 {
		for i < l1 {
			s[k] = nums1[i]
			k++
			i++
		}
	}
	if j != l2 {
		for j < l2 {
			s[k] = nums2[j]
			k++
			j++
		}
	}
	fmt.Println(s)
	if (l1+l2)%2 == 0 {
		o := int((l1 + l2) / 2)
		return float64((float64(s[o]) + float64(s[o-1])) / 2)
	} else {
		return float64(s[(l1+l2-1)/2])
	}
}

func main() {
	nums1 := []int{0, 0, 0, 0, 0}
	nums2 := []int{-1, 0, 0, 0, 0, 0, 1}
	fmt.Println(findMedianSortedArrays(nums1, nums2))
}

// @lc code=end
