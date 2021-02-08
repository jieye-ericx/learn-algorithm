/**
 * 
题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
输入描述:
输入一个数n，意义见题面。（2 <= n <= 60）
输出描述:
输出答案。
示例1
输入

复制
8
输出

复制
18
 */
function cutRope(number) {
  if (number === 2 || number === 3) {
    return number - 1
  }
  // write code here
  const m = number % 3 === 0 ? number / 3 : Math.ceil(number / 3),
    base = Math.floor(number / m),
    remains = number % m
  return Math.pow(base, m - remains) * Math.pow(base + 1, remains)
}
