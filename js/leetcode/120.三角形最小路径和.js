/**
 * 
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 */
/**
 * 因为用了一维数组，
 * 我这里的dp[j]表示从上往下运算到第i层时，最后一个点是的index是j的情况下，最短的长度，
 * 最后一层运算完后再找出最小值返回即可
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function (triangle) {
    if (!triangle.length) return 0
    let deep = triangle.length, dplen = triangle[deep - 1].length
    let dp = Array(dplen).fill(0)
    dp[0] = triangle[0][0]
    // console.log(deep);
    // console.log(dplen);
    // console.log(dp);
    for (let i = 1; i < deep; i++) {
        for (let j = i; j >= 0; j--) {
            if (j === i) {
                dp[j] = dp[j - 1]
            } else if (j === 0) {
                // dp[j] += triangle[i - 1][0]
            } else {
                dp[j] = Math.min(dp[j], dp[j - 1])
            }
            dp[j] += triangle[i][j]
        }
        // console.log(i + " i " + dp);
    }
    return Math.min(...dp)
};

minimumTotal([
    [2],
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
])