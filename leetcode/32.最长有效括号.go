/*
 * @lc app=leetcode.cn id=32 lang=golang
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (37.07%)
 * Likes:    2165
 * Dislikes: 0
 * Total Accepted:    349.3K
 * Total Submissions: 941.3K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s[i] 为 '(' 或 ')'
 *
 *
 *
 *
 */
package main

// @lc code=start
func longestValidParentheses(s string) int {
	// dp[i]表示
	if len(s) <= 1 {
		return 0
	}
	dp := make([]int, len(s))
	if s[0] == '(' && s[1] == ')' {
		dp[1] = 2
	}
	for i := 2; i < len(s); i++ {
		if s[i] == ')' {
			if s[i-1] == '(' {
				dp[i] = dp[i-2] + 2
			} else if i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(' {
				dp[i] = dp[i-1] + 2
				if i-dp[i-1]-2 >= 0 {
					dp[i] += dp[i-dp[i-1]-2]
				}
			}
		}
	}
	ans := 0
	for i := 0; i < len(s); i++ {
		ans = max(dp[i], ans)
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
