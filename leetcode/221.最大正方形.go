/*
 * @lc app=leetcode.cn id=221 lang=golang
 *
 * [221] 最大正方形
 *
 * https://leetcode.cn/problems/maximal-square/description/
 *
 * algorithms
 * Medium (49.45%)
 * Likes:    1367
 * Dislikes: 0
 * Total Accepted:    251.9K
 * Total Submissions: 509.2K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：matrix = [["0"]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * matrix[i][j] 为 '0' 或 '1'
 *
 *
 */

// @lc code=start
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
