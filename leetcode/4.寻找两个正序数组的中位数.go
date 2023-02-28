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
    totalLength := len(nums1) + len(nums2)
    if totalLength%2 == 1 {
        midIndex := totalLength/2
        return float64(getKthElement(nums1, nums2, midIndex + 1))
    } else {
        midIndex1, midIndex2 := totalLength/2 - 1, totalLength/2
        return float64(getKthElement(nums1, nums2, midIndex1 + 1) + getKthElement(nums1, nums2, midIndex2 + 1)) / 2.0
    }
    return 0
}

func getKthElement(nums1, nums2 []int, k int) int {
    index1, index2 := 0, 0
    for {
        if index1 == len(nums1) {
            return nums2[index2 + k - 1]
        }
        if index2 == len(nums2) {
            return nums1[index1 + k - 1]
        }
        if k == 1 {
            return min(nums1[index1], nums2[index2])
        }
        half := k/2
        newIndex1 := min(index1 + half, len(nums1)) - 1
        newIndex2 := min(index2 + half, len(nums2)) - 1
        pivot1, pivot2 := nums1[newIndex1], nums2[newIndex2]
        if pivot1 <= pivot2 {
            k -= (newIndex1 - index1 + 1)
            index1 = newIndex1 + 1
        } else {
            k -= (newIndex2 - index2 + 1)
            index2 = newIndex2 + 1
        }
    }
    return 0
}

func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// 这个方法的复杂度虽然是M+N，但是仍然没有达到题目说的最优
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	i, j, k := 0, 0, 0
	l1, l2 := len(nums1), len(nums2)
	midIndex1, midIndex2 := (l1+l2)/2-1, (l1+l2)/2
	var mid1, mid2 int
	for ; i < l1 && j < l2 && k <= midIndex2; k++ {
		if nums1[i] <= nums2[j] {
			if k == midIndex1 {
				mid1 = nums1[i]
			}
			if k == midIndex2 {
				mid2 = nums1[i]
			}
			i++
		} else {
			if k == midIndex1 {
				mid1 = nums2[j]
			}
			if k == midIndex2 {
				mid2 = nums2[j]
			}
			j++
		}
	}
	if k != midIndex2+1 {
		if i != l1 {
			for ; i < l1; i++ {
				if k == midIndex1 {
					mid1 = nums1[i]
				}
				if k == midIndex2 {
					mid2 = nums1[i]
					break
				}
				k++
			}
		}
		if j != l2 {
			for ; j < l2; j++ {
				if k == midIndex1 {
					mid1 = nums2[j]
				}
				if k == midIndex2 {
					mid2 = nums2[j]
					break
				}
				k++
			}
		}
	}
	if (l1+l2)%2 == 0 {
		return (float64(mid1) + float64(mid2)) / 2
	} else {
		return float64(mid2)
	}
}

func main() {
	nums1 := []int{1, 2}
	nums2 := []int{3, 4}
	fmt.Println(findMedianSortedArrays(nums1, nums2))
}

// @lc code=end
