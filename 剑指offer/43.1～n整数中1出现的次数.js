/**
 * 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。



示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6


限制：
1 <= n < 2^31
 */

/**
* @param {number} n
* @return {number}
*/
let countDigitOne = function (n) {
  let count = 0, i = 1, pre = 0, back = 0, cur = 0;
  while (n >= i) {
    pre = parseInt(n / (i * 10));
    back = n - parseInt(n / i) * i;
    cur = parseInt(n / i) % 10;
    if (cur == 0) {
      count += pre * i;
    } else if (cur == 1) {
      count += pre * i + back + 1;
    } else {
      count += (pre + 1) * i
    }
    i *= 10;
  }
  return count;
};