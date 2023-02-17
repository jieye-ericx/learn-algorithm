/*
 * @lc app=leetcode.cn id=1139 lang=golang
 *
 * [1139] 最大的以 1 为边界的正方形
 *
 * https://leetcode.cn/problems/largest-1-bordered-square/description/
 *
 * algorithms
 * Medium (49.51%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 49.2K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回
 * 0。
 *
 *
 *
 * 示例 1：
 *
 * 输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：9
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[1,1,0,0]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length <= 100
 * 1 <= grid[0].length <= 100
 * grid[i][j] 为 0 或 1
 *
 *
 */

// @lc code=start
// ? 肯定是dp
// dp[i][j]表示以ij节点为右下角顶点的正方形的最大边长
package main

import "fmt"

func main() {
	fmt.Println(largest1BorderedSquare([][]int{{1, 1, 0, 0}}))
}

// https://leetcode.cn/problems/largest-1-bordered-square/solution/zui-da-de-yi-1-wei-bian-jie-de-zheng-fan-74ce/
func largest1BorderedSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	left := make([][]int, m+1)
	up := make([][]int, m+1)
	for i := range left {
		left[i] = make([]int, n+1)
		up[i] = make([]int, n+1)
	}
	maxBorder := 0
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if grid[i-1][j-1] == 1 {
				left[i][j] = left[i][j-1] + 1
				up[i][j] = up[i-1][j] + 1
				border := min(left[i][j], up[i][j])
				for left[i-border+1][j] < border || up[i][j-border+1] < border {
					border--
				}
				maxBorder = max(maxBorder, border)
			}
		}
	}
	return maxBorder * maxBorder
}

// ! 辛苦了半天没发现题目要求的正方形中间是可以有0的 这是221题
func maximalSquare(grid [][]byte) int {
	M, N := len(grid), len(grid[0])
	dp := make([][]int, M)
	ans := 0
	for i, _ := range dp {
		dp[i] = make([]int, N)
	}
	for i := 0; i < M; i++ {
		if grid[i][0] == '1' {
			dp[i][0] = 1
			ans = 1
		}
	}
	for i := 1; i < N; i++ {
		if grid[0][i] == '1' {
			dp[0][i] = 1
			ans = 1
		}
	}
	for i := 1; i < M; i++ {
		for j := 1; j < N; j++ {
			if dp[i-1][j] == 0 || dp[i][j-1] == 0 || grid[i][j] == '0' {
				if grid[i][j] == '1' {
					dp[i][j] = 1
					ans = max(ans, dp[i][j])
				} else {
					dp[i][j] = 0
				}
			} else {
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1
				ans = max(ans, dp[i][j])
			}
		}
	}
	return ans * ans
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a <= b {
		return b
	}
	return a
}

// @lc code=end
