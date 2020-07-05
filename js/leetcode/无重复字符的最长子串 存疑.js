/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */

/**
 * 我的思路是滑动窗口，但是由于采用了映射法，对于感叹号等字符无法处理，以后再解决
 */
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  if (s.length === 0) return 0
  s = s.trim()
  if (s.length === 0) return 1
  const trans = {
    a: 0,
    b: 1,
    c: 2,
    d: 3,
    e: 4,
    f: 5,
    g: 6,
    h: 7,
    i: 8,
    j: 9,
    k: 10,
    l: 11,
    m: 12,
    n: 13,
    o: 14,
    p: 15,
    q: 16,
    r: 17,
    s: 18,
    t: 19,
    u: 20,
    v: 21,
    w: 22,
    x: 23,
    y: 24,
    z: 25,
  }
  let vis = new Array(26).fill(-1),
    ans = 0,
    len = 0,
    st = 0,
    ed = 0
  for (let index = 0; index < s.length; index++) {
    if (vis[trans[s[index]]] === -1 || vis[trans[s[index]]] < st) {
      // 代表当前字母在子串中未出现过
      vis[trans[s[index]]] = index
      len++
    } else {
      len -= vis[trans[s[index]]] - st
      st = vis[trans[s[index]]] + 1
      vis[trans[s[index]]] = index
    }
    ans = Math.max(ans, len)
  }
  return ans
}

console.log(lengthOfLongestSubstring('abcabcbb'))
