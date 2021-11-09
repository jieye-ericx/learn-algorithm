/*
 * @lc app=leetcode.cn id=313 lang=javascript
 *
 * [313] 超级丑数
 *
 * https://leetcode-cn.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (64.75%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 40.6K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * 超级丑数 是一个正整数，并满足其所有质因数都出现在质数数组 primes 中。
 *
 * 给你一个整数 n 和一个整数数组 primes ，返回第 n 个 超级丑数 。
 *
 * 题目数据保证第 n 个 超级丑数 在 32-bit 带符号整数范围内。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 12, primes = [2,7,13,19]
 * 输出：32
 * 解释：给定长度为 4 的质数数组 primes = [2,7,13,19]，前 12
 * 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, primes = [2,3,5]
 * 输出：1
 * 解释：1 不含质因数，因此它的所有质因数都在质数数组 primes = [2,3,5] 中。
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^6
 * 1 <= primes.length <= 100
 * 2 <= primes[i] <= 1000
 * 题目数据 保证 primes[i] 是一个质数
 * primes 中的所有值都 互不相同 ，且按 递增顺序 排列
 *
 *
 *
 *
 *
 */

// @lc code=start
/**
 * @param {number} n
 * @param {number[]} primes
 * @return {number}
 */
var nthSuperUglyNumber = function (n, primes) {
  // primes.sort((a, b) => a - b)
  let ans = new Array(n + 1),
    lastNum = 1,
    nn = primes.length,
    base = new Array(nn).fill(1)
  ans[1] = 1
  for (let i = 2; i <= n; i++) {
    let tmp = {
      val: Infinity, index: [- 1]
    }
    let j = 0
    for (; j < nn; j++) {
      // !下面的写法虽然(ans[base[j]] * primes[j] > ans[i - 1])过滤了重复值，但是如3*7和7*3
      // !应该两个j都要++，这里只加了一个，所以会导致错过一些中间值
      // !仔细看264题，这里的if没有else，所以一次可能有多个指针都++，避免了重复值或者漏值的问题
      /**
       * let p2 = 1, p3 = 1, p5 = 1, i = 2;
          while (i <= n) {
            ans[i] = Math.min(ans[p2] * 2, Math.min(ans[p3] * 3, ans[p5] * 5));
            if (ans[p2] * 2 == ans[i]) p2++;
            if (ans[p3] * 3 == ans[i]) p3++;
            if (ans[p5] * 5 == ans[i]) p5++;
            i++
          }
       */
      // !
      // if ((ans[base[j]] * primes[j] > ans[i - 1]) && (ans[base[j]] * primes[j] < tmp.val)) {
      //   tmp.val = ans[base[j]] * primes[j]
      //   tmp.index = j
      // }
      if (ans[base[j]] * primes[j] < tmp.val) {
        tmp.val = ans[base[j]] * primes[j]
        tmp.index = [j]
      } else if (ans[base[j]] * primes[j] === tmp.val) {
        tmp.index.push(j)
      }
    }
    tmp.index.forEach(ele => base[ele]++)
    // base[tmp.index]++
    ans[i] = tmp.val
    // console.log('i=' + i, ' val=' + ans[i], base);
    // console.log(ans);
  }

  return ans[n]
};
nthSuperUglyNumber(15, [3, 5, 7, 11, 19, 23, 29, 41, 43, 47])
// @lc code=end
