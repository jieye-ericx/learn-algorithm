/*
 * @lc app=leetcode.cn id=56 lang=golang
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (49.25%)
 * Likes:    1815
 * Dislikes: 0
 * Total Accepted:    594.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2：
 *
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
 */
package main

import "sort"

// @lc code=start
func merge(intervals [][]int) (ans [][]int) {
	if len(intervals) == 0 {
		return [][]int{}
	}
	sort.SliceStable(intervals, func(i, j int) bool {
		if intervals[i][0] == intervals[j][0] {
			return intervals[i][1] < intervals[j][1]
		}
		return intervals[i][0] < intervals[j][0]
	})
	ans = [][]int{intervals[0]}
	for i := 1; i < len(intervals)-1; {
		for i < len(intervals)-2 && intervals[i][0] == intervals[i+1][0] {
			i++
		}
		if ans[len(ans)-1][1] < intervals[i][0] {
			ans = append(ans, []int{intervals[i][0], intervals[i][1]})
		} else if ans[len(ans)-1][1] < intervals[i][1] {
			ans[len(ans)-1][1] = intervals[i][1]
		}
		i++
	}
	if ans[len(ans)-1][1] < intervals[len(intervals)-1][0] {
		ans = append(ans, []int{intervals[len(intervals)-1][0], intervals[len(intervals)-1][1]})
	} else if ans[len(ans)-1][1] < intervals[len(intervals)-1][1] {
		ans[len(ans)-1][1] = intervals[len(intervals)-1][1]
	}

	return ans
}

// func main() {
// 	a := [][]int{{1, 3}, {2, 6}, {8, 10}, {15, 18}}
// 	merge(a)
// }

// @lc code=end
