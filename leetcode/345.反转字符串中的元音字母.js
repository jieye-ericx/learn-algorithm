/*
 * @lc app=leetcode.cn id=345 lang=javascript
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (51.82%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    91.7K
 * Total Submissions: 173.6K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 *
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "hello"
 * 输出："holle"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "leetcode"
 * 输出："leotcede"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 *
 *
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function (s) {
  const yy = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"];
  let y = new Map(),
    n = s.length;
  for (const ele of yy) {
    y.set(ele, 1);
  }
  s = s.split("");
  let i = 0,
    j = s.length - 1;
  while (i < j) {
    while (!y.has(s[i]) && i < n) {
      i++;
    }
    while (!y.has(s[j]) && j >= 0) {
      j--;
    }
    if (i >= j) break;
    let t = s[i];
    s[i] = s[j];
    s[j] = t;
    // console.log(s.join(''));
    // console.log(i, j);
    i++, j--;
  }
  return s.join("");
};
// console.log(reverseVowels(".,"));
// @lc code=end
