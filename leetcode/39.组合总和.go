/*
 * @lc app=leetcode.cn id=39 lang=golang
 *
 * [39] 组合总和
 *
 * https://leetcode.cn/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.64%)
 * Likes:    2378
 * Dislikes: 0
 * Total Accepted:    686.6K
 * Total Submissions: 945.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target
 * 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
 *
 * candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
 *
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：candidates = [2,3,6,7], target = 7
 * 输出：[[2,2,3],[7]]
 * 解释：
 * 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
 * 7 也是一个候选， 7 = 7 。
 * 仅有这两种组合。
 *
 * 示例 2：
 *
 *
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * 示例 3：
 *
 *
 * 输入: candidates = [2], target = 1
 * 输出: []
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * candidates 的所有元素 互不相同
 * 1 <= target <= 40
 *
 *
 */

// @lc code=start
package main

import (
	"sort"
)

func combinationSum(candidates []int, target int) [][]int {
	n := len(candidates)
	sort.Ints(candidates)
	ans := [][]int{}
	// !有了下面的方法就不需要m去重了
	// m := map[string]int{}
	var dfs func(tmpI, left int, cmp []int)

	dfs = func(tmpI, left int, cmp []int) {
		if left == 0 {
			// !注意这里cmp因为是指针，直接复制会有数据的不一致问题
			a := make([]int, len(cmp))
			copy(a, cmp)
			ans = append(ans, a)
			return
		}

		for i := 0; i < n && candidates[i] <= left; i++ {
			// ! i > tmpI 就可以避免判断是否去重了,即防止1，1，4，5，6这种有两个1的数组，太妙了
			if i > tmpI && candidates[i] == candidates[i-1] {
				continue
			}
			if len(cmp) >= 1 && cmp[len(cmp)-1] > candidates[i] {
				continue
			}
			dfs(tmpI+1, left-candidates[i], append(cmp, candidates[i]))
		}
	}
	dfs(0, target, []int{})
	return ans
}

// func main() {
// 	combinationSum([]int{2, 3}, 6)
// }

// @lc code=end
