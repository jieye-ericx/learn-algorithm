/*
 * @lc app=leetcode.cn id=440 lang=golang
 *
 * [440] 字典序的第K小数字
 *
 * https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (42.65%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    47K
 * Total Submissions: 110.1K
 * Testcase Example:  '13\n2'
 *
 * 给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: n = 13, k = 2
 * 输出: 10
 * 解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
 *
 *
 * 示例 2:
 *
 *
 * 输入: n = 1, k = 1
 * 输出: 1
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= k <= n <= 10^9
 *
 *
 */

// @lc code=start
package main

// func main() {
// 	fmt.Println(findKthNumber(100, 90))
// }

// !遍历会超时！
// func findKthNumber(n int, k int) int {
// 	cnt := 0
// 	var ans int
// 	var recursion func(int)
// 	recursion = func(d int) {
// 		if d > n || cnt == k {
// 			return
// 		}
// 		cnt++
// 		fmt.Println(d)
// 		if cnt == k {
// 			ans = d
// 			return
// 		}
// 		recursion(d * 10)
// 		li := d % 10
// 		if li != 9 {
// 			recursion(d + 1)
// 		} else {
// 			return
// 		}
// 	}
// 	recursion(1)
// 	return ans
// }

// ！写得很妙
func getSteps(cur, n int) (steps int) {
	first, last := cur, cur
	for first <= n {
		steps += min(last, n) - first + 1
		first *= 10
		last = last*10 + 9
	}
	return
}

func findKthNumber(n, k int) int {
	cur := 1
	k--
	for k > 0 {
		steps := getSteps(cur, n)
		if steps <= k {
			k -= steps
			cur++
		} else {
			cur *= 10
			k--
		}
	}
	return cur
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

// @lc code=end
