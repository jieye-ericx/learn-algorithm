/*
 * @lc app=leetcode.cn id=44 lang=golang
 *
 * [44] 通配符匹配
 *
 * https://leetcode.cn/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (33.81%)
 * Likes:    1032
 * Dislikes: 0
 * Total Accepted:    135.1K
 * Total Submissions: 399.6K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个输入字符串 (s) 和一个字符模式 (p) ，请你实现一个支持 '?' 和 '*' 匹配规则的通配符匹配：
 *
 *
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符序列（包括空字符序列）。
 *
 *
 *
 *
 * 判定匹配成功的充要条件是：字符模式必须能够 完全匹配 输入字符串（而不是部分匹配）。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aa", p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "aa", p = "*"
 * 输出：true
 * 解释：'*' 可以匹配任意字符串。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "cb", p = "?a"
 * 输出：false
 * 解释：'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length, p.length <= 2000
 * s 仅由小写英文字母组成
 * p 仅由小写英文字母、'?' 或 '*' 组成
 *
 *
 */

// @lc code=start
package main

// func main() {
// 	isMatch("mississippi", "m??*ss*?i*pi")
// }

// !dp https://leetcode.cn/problems/wildcard-matching/solution/yi-ge-qi-pan-kan-dong-dong-tai-gui-hua-dpsi-lu-by-/
// 虽然可以通过，但是流程控制判断比较复杂，感觉不具备可复制性，主要是因为我的解法只能斜下方走，如果能可以向下或者向右走流程控制应该会简单不少
func isMatch(s string, p string) bool {
	i := 0
	for ; i < len(p) && p[i] == '*'; i++ {

	}
	if (s == "" && p == "") || (i == len(p) && i > 0) {
		return true
	}
	m, n := len(p), len(s)
	s = "0" + s
	p = "0" + p
	dp := make([][]int, m+1)
	for i := 0; i < m+1; i++ {
		dp[i] = make([]int, n+1)
	}
	dp[0][0] = 1
	i, j := 1, 1
	for ; j < n+1 && i < m+1; i++ {
		if p[i] == '*' {
			if dp[i-1][j-1] == 1 {
				j--
			}
			for k := j; k < n+1; k++ {
				dp[i][k] = 1
			}
			if j < 1 {
				j = 1
			}
		} else {
			for k := j; k < n+1; k++ {
				if dp[i-1][k-1] == 1 {
					if s[k] == p[i] || p[i] == '?' {
						dp[i][k] = 1
					}
				}
			}
			k := j
			for ; k < n+1; k++ {
				if dp[i][k] == 1 {
					break
				}
			}
			j = k
		}
	}
	// for i := 0; i < m+1; i++ {
	// 	fmt.Println(dp[i])
	// }
	return dp[m][n] == 1
}

// ! 1717/1811 cases passed (N/A)超时无能为力啦
// func isMatch(s string, p string) bool {
// 	i := 0
// 	for ; i < len(p) && p[i] == '*'; i++ {

// 	}
// 	if (s == "" && p == "") || (i == len(p) && i > 0) {
// 		return true
// 	}
// 	isOk, No := false, false
// 	dfs(0, 0, len(s), len(p), &isOk, &No, &s, &p)
// 	return isOk
// }
// func dfs(i, j, I, J int, ok, no *bool, s, p *string) {
// 	// fmt.Println(i, j)
// 	if i == I {
// 		k := j
// 		// 对于s已经匹配完，但是p后面还剩很多*的情况
// 		for ; k < J && (*p)[k] == '*'; k++ {
// 		}
// 		if k == J {
// 			*ok = true
// 		}
// 		return
// 	}
// 	if *ok || *no || i >= I || j >= J {
// 		return
// 	}
// 	if (*p)[j] == '*' {
// 		for j < J && (*p)[j] == '*' {
// 			j++
// 		}
// 		if j == J {
// 			*ok = true
// 			return
// 		}
// 		run := false
// 		for ; i < I && !*ok; i++ {
// 			if (*s)[i] == (*p)[j] || (*p)[j] == '?' {
// 				run = true
// 				dfs(i+1, j+1, I, J, ok, no, s, p)
// 			}
// 		}
// 		if !run {
// 			*no = true
// 		}
// 	} else if (*p)[j] == '?' || (*p)[j] == (*s)[i] {
// 		dfs(i+1, j+1, I, J, ok, no, s, p)
// 	}
// }

// @lc code=end
