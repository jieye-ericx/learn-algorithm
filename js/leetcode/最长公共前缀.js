/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
 */

/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  if (strs.length === 0) return ''
  if (strs.length === 1) return strs[0]
  strs.sort((a, b) => a.length > b.length)
  let flag = false,
    ans = strs[0]
  while (flag!==true) {
    for (let i = 1; i < strs.length; i++) {
      if (!strs[i].startsWith(ans)) {
        break
      }
      if (i === strs.length - 1) {
        flag=true
      }
    }
    if (flag === true) {
      break
    }
    ans = ans.slice(0, ans.length - 1)
    if (ans === '') {
      break
    }
  }
  return ans
}

console.log(longestCommonPrefix(['flower', 'flow', 'flight']))
console.log(longestCommonPrefix(['dog', 'racecar', 'car']))
