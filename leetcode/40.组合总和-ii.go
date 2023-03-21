/*
 * @lc app=leetcode.cn id=40 lang=golang
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.22%)
 * Likes:    1263
 * Dislikes: 0
 * Total Accepted:    399.5K
 * Total Submissions: 664.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

package main

import (
	"sort"
)

// @lc code=start
func combinationSum2(candidates []int, target int) [][]int {
	n := len(candidates)
	sort.Ints(candidates)
	ans := [][]int{}
	var dfs func(tmpI, left int, cmp []int)

	dfs = func(tmpI, left int, cmp []int) {
		if left == 0 {
			// !注意这里cmp因为是指针，直接复制会有数据的不一致问题
			a := make([]int, len(cmp))
			copy(a, cmp)
			ans = append(ans, a)
			return
		}
		if tmpI == n {
			return
		}
		for i := tmpI; i < n && candidates[i] <= left; i++ {
			// ! i > tmpI candidates[i] == candidates[i-1]就可以避免判断是否去重了,即防止1，1，4，5，6这种有两个1的数组，太妙了
			if i > tmpI && candidates[i] == candidates[i-1] {
				continue
			}
			if len(cmp) >= 1 && cmp[len(cmp)-1] > candidates[i] {
				continue
			}
			dfs(i+1, left-candidates[i], append(cmp, candidates[i]))
		}
	}
	dfs(0, target, []int{})
	return ans
}

// func main() {
// 	combinationSum2([]int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 30)
// }

// @lc code=end
