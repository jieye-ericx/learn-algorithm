/**
 * 编写一个程序判断给定的数是否为丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例 1:

输入: 6
输出: true
解释: 6 = 2 × 3
示例 2:

输入: 8
输出: true
解释: 8 = 2 × 2 × 2
示例 3:

输入: 14
输出: false
解释: 14 不是丑数，因为它包含了另外一个质因数 7。
说明：

1 是丑数。
输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。
 */

/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function (num) {
  if (num <= 0) return false;
  if (num === 1) return true
  let ans = Array(num + 1);
  ans[1] = 1;
  let p2 = 1, p3 = 1, p5 = 1;
  for (let i = 2; ; i++) {
    ans[i] = Math.min(ans[p2] * 2, Math.min(ans[p3] * 3, ans[p5] * 5));
    if (ans[i] === num) return true
    else if (ans[i] > num) return false
    if (ans[p2] * 2 == ans[i]) p2++;
    if (ans[p3] * 3 == ans[i]) p3++;
    if (ans[p5] * 5 == ans[i]) p5++;
  }
};