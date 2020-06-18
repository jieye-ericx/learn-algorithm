/**
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
 */
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function (matrix) {
  if (matrix.length === 0) return 0
  let ans = [],
    maxN = 0
  for (let i = 0; i < matrix.length; i++) {
    ans.push(new Array(matrix[0].length).fill(0))
  }
  for (let i = 0; i < matrix.length; i++) {
    ans[i][0] = matrix[i][0] === '1' ? 1 : 0
    if (ans[i][0] === 1) maxN = 1
  }
  for (let i = 0; i < matrix[0].length; i++) {
    ans[0][i] = matrix[0][i] === '1' ? 1 : 0
    if (ans[0][i] === 1) maxN = 1
  }
  for (let i = 1; i < matrix.length; i++) {
    for (let j = 1; j < matrix[i].length; j++) {
      ans[i][j] =
        matrix[i][j] === '1'
          ? Math.min(ans[i - 1][j - 1], ans[i - 1][j], ans[i][j - 1]) + 1
          : 0
      maxN = Math.max(maxN, ans[i][j])
    }
  }
  return maxN * maxN
}
const m = [
  [1, 0, 1, 0, 0],
  [1, 1, 1, 1, 1],
  [1, 0, 1, 1, 1],
  [1, 0, 0, 1, 0],
]
const n = [
  ['1', '0', '1', '0'],
  ['1', '0', '1', '1'],
  ['1', '0', '1', '1'],
  ['1', '1', '1', '1'],
]
console.log(maximalSquare(n))
