/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
 */
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  if (!s || s.length === 0) return ''
  let dp = Array(s.length),
    ans = s[0]
  for (let i = 0; i < s.length; i++) {
    dp[i] = new Array(s.length).fill(0)
  }

  // -------dp[i][j]=dp[i+1][j-1]===1&&s[i]===s[j]
  for (let i = s.length - 1; i >= 0; i--) {
    dp[i][i] = 1
    for (let j = i + 1; j < s.length; j++) {
      if (j - i === 1) {
        //这里如果成立，则说明是abbc中bb这种连续两个的情况，则不需要dp[i + 1][j - 1]
        dp[i][j] = s[i] === s[j] ? 1 : 0
      } else dp[i][j] = dp[i + 1][j - 1] === 1 && s[i] === s[j] ? 1 : 0
      //   console.log('dp[' + i + '][' + j + ']=' + dp[i][j])
      if (dp[i][j] === 1 && j - i + 1 > ans.length) {
        ans = s.slice(i, j + 1)
      }
    }
  }
  //   console.log(dp)
  return ans
}

console.log(longestPalindrome('cbbd'))
