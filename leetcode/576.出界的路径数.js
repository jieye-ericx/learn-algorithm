/*
 * @lc app=leetcode.cn id=576 lang=javascript
 *
 * [576] 出界的路径数
 *
 * https://leetcode-cn.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (39.28%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 37.7K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * 给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn]
 * 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。
 *
 * 给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对
 * 10^9 + 7 取余 后的结果。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
 * 输出：6
 *
 *
 * 示例 2：
 *
 *
 * 输入：m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
 * 输出：12
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 50
 * 0 <= maxMove <= 50
 * 0 <= startRow < m
 * 0 <= startColumn < n
 *
 *
 */

// @lc code=start
/**
 * @param {number} m
 * @param {number} n
 * @param {number} maxMove
 * @param {number} startRow
 * @param {number} startColumn
 * @return {number}
 */
var findPaths = function (m, n, maxMove, startRow, startColumn) {
  let dir = [
    [0, 1],
    [1, 0],
    [-1, 0],
    [0, -1],
  ], ans = 0,
    added = new Array(m).fill(0).map(() => new Array(n).fill(0))
  // console.log(added);
  let dfs = (x, y, step) => {
    // 说明到了边界
    if (maxMove === step) {
      return
    }
    // !超时了，尝试剪枝
    // if (Math.min(x + 1, y + 1, m - x + 1, n - y + 1) > maxMove - step) {
    //   return
    // }
    // console.log(x, y);
    if (x <= 0 || y <= 0 || x >= m - 1 || y >= n - 1) {
      // 走到边界后，如果还有步数，就能走出去，同时也需要检查这个位置是否已经计算过了
      // if (added[x][y] === 0) {
      //   added[x][y] = 1
      if (x === 0) ans += 1
      if (y === 0) ans += 1
      if (x === m - 1) ans += 1
      if (y === n - 1) ans += 1
      ans %= (Math.pow(10, 9) + 7)
      // console.log(ans, x, y);
      // }
    }
    let nx, ny
    for (const [xx, yy] of dir) {
      nx = x + xx, ny = y + yy
      if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
        continue
      }
      dfs(nx, ny, step + 1)
    }
  }
  dfs(startRow, startColumn, 0)
  // console.log(ans);
  return ans
};
findPaths(10, 4, 11, 6, 2)

// @lc code=end
