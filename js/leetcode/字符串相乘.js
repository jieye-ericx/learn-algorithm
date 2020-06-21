/**
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 */
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function (num1, num2) {
  if (num1 === '0' || num2 === '0') return '0'
  let smallNum = num1.length <= num2.length ? num1 : num2,
    bigNum = num1.length <= num2.length ? num2 : num1,
    answer = [],
    outcome = []
  maxlen = 0
  for (let i = smallNum.length - 1; i >= 0; i--) {
    let turn = [],
      ans = 0,
      plus = 0
    console.log(smallNum[i])

    for (let j = bigNum.length - 1; j >= 0; j--) {
      ans = Number(smallNum[i]) * Number(bigNum[j]) + (plus !== 0 ? plus : 0)
      console.log('j= ' + j + 'ans= ' + ans)

      turn.push(ans % 10)
      plus = Math.floor(ans / 10)
    }
    plus !== 0 ? turn.push(plus) : ''
    for (let k = 0; k < smallNum.length - i - 1; k++) {
      turn.unshift(0)
    }
    answer.push(turn)
    maxlen = Math.max(turn.length, maxlen)
    console.log(turn)
  }
  let val = 0,
    plus = 0
  console.log(answer)

  for (let i = 0; i < maxlen; i++) {
    for (let j = answer.length - 1; j >= 0; j--) {
      if (answer[j][i] !== undefined) {
        val += answer[j][i]
        // console.log('jiale++++ ' + answer[j][i])
      } else {
        // console.log('i==' + i + ' j==' + j)
        break
      }
    }

    val += plus
    outcome.unshift(val % 10)
    plus = Math.floor(val / 10)
    val = 0
    // console.log(outcome)
  }
  if (plus !== 0) outcome.unshift(plus)
  return outcome.join('')
}
// '123456789'
// '987654321'
console.log(multiply('123456789', '987654321'))
