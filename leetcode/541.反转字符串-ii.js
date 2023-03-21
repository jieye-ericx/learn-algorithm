/*
 * @lc app=leetcode.cn id=541 lang=javascript
 *
 * [541] 反转字符串 II
 *
 * https://leetcode-cn.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (57.84%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    55.4K
 * Total Submissions: 92.3K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每 2k 个字符反转前 k 个字符。
 *
 *
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 *
 *
 */

// @lc code=start
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function (s, k) {
  let ss = s.split(""),
    n = ss.length;
  let i = (j = 0),
    set = [];
  while ((i + 1) * k < n) {
    set.push(ss.slice(i * k, (i + 1) * k));
    i++;
  }
  // !此时i代表这set的元素个数，但i*k并不一定大于等于n
  // console.log(set, i * k, i, n);
  for (let k = 0; k < i; k += 2) {
    set[k].reverse();
  }
  if (i * k < n) {
    if (!(i & 1)) {
      set.push(ss.slice(i * k).reverse());
    } else {
      set.push(ss.slice(i * k));
    }
  }
  return set.flat().join("");
};
// reverseStr("abcdefg", (k = 2));
// @lc code=end
