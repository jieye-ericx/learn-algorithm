/*
 * @lc app=leetcode.cn id=516 lang=javascript
 *
 * [516] 最长回文子序列
 *
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (62.16%)
 * Likes:    559
 * Dislikes: 0
 * Total Accepted:    69.5K
 * Total Submissions: 108.5K
 * Testcase Example:  '"bbbab"'
 *
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 *
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindromeSubseq = function (s) {
  // !按照目前的记忆,可以将s与反转后的s求最长公共子序列的长度即可
  let n = s.length,
    rev = s.split('').reverse().join('')
  dp = new Array(n + 1).fill(0).map(() =>
    new Array(n + 1).fill(0)
  )

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      if (s[i - 1] === rev[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
      }
    }
  }
  // console.log(dp);
  return dp[n][n]
};
longestPalindromeSubseq("bbbab")


// @lc code=end
