/**
 * 
题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[1],...,k[m]。
请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
输入描述:
输入一个数n，意义见题面。（2 <= n <= 60）
输出描述:
输出答案。
示例1
输入
8
输出
18
 */
// dp求解 
const cutRope = (num) => {
  if (num === 2 || num === 3) return num - 1
  let arr = Array(num + 1).fill(0);
  arr[1] = 1, arr[2] = 2, arr[3] = 3, arr[4] = 4
  for (let i = 5; i <= num; i++) {
    for (let j = 1; j < i; j++) {
      arr[i] = Math.max(arr[i], j * arr[i - j])
    }
  }
  // console.log(arr);
  return arr[num]
}
//上面的dp是时隔245天后我实在没招的方法
// 下面这个是我之前写的，为数学方法

function cutRope(number) {
  if (number === 2 || number === 3) {
    return number - 1
  }
  // write code here
  const m = number % 3 === 0 ? number / 3 : Math.ceil(number / 3),//段数
    base = Math.floor(number / m),
    remains = number % m
  return Math.pow(base, m - remains) * Math.pow(base + 1, remains)
}
console.log(cutRope(58));