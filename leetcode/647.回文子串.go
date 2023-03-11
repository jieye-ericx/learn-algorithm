/*
 * @lc app=leetcode.cn id=647 lang=golang
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (66.92%)
 * Likes:    1086
 * Dislikes: 0
 * Total Accepted:    254.2K
 * Total Submissions: 379.8K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 *
 * 回文字符串 是正着读和倒过来读一样的字符串。
 *
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 *
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 *
 *
 */

// @lc code=start
func countSubstrings(s string) (ans int) {
	ans = 0
	n := len(s)
	dp := make([][]bool, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]bool, n+1)
	}
	// !使用dp判断s[i-j]是否是回文
	for i := n; i >= 0; i-- {
		for j := i + 1; j < n+1; j++ {
			if s[i-1] == s[j-1] {
				if dp[i+1][j-1] {
					dp[i][j] = true
				}
			}
		}
	}
	for i := 0; i < n+1; i++ {
		for j := 0; j < n+1; j++ {
			if dp[i][j] {
				ans += 1
			}
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
