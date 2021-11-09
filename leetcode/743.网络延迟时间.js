/*
 * @lc app=leetcode.cn id=743 lang=javascript
 *
 * [743] 网络延迟时间
 *
 * https://leetcode-cn.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (48.32%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    37.2K
 * Total Submissions: 75.1K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 *
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 *
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * times[i].length == 3
 * 1 i, vi
 * ui != vi
 * 0 i
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
 *
 *
 */

// @lc code=start
/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var networkDelayTime = function (times, n, k) {
  let routes = new Array(n + 1).fill(0).map(() => []),
    stack = [k],
    ans = new Array(n + 1).fill(-Infinity),
    vis = new Array(n + 1).fill(0),
    reach = new Array(n + 1).fill(0),
    dfs = (cost, node) => {
      reach[node] = 1
      // if (routes[node].length === 0) {
      ans[node] = ans[node] === -Infinity ? cost : Math.min(cost, ans[node])
      // console.log(ans);
      // }
      // else {
      for (const obj of routes[node]) {
        if (vis[obj.to]) continue
        vis[obj.to] = 1
        dfs(cost + obj.cos, obj.to)
        vis[obj.to] = 0
      }
      // }
    }
  vis[k] = 1, vis[0] = 1, reach[0] = 1
  // console.log(routes);
  for (let ele of times) {
    routes[ele[0]].push({ to: ele[1], cos: ele[2] })
  }

  dfs(0, k)

  return reach.findIndex(ele => ele === 0) === -1 ? Math.max(...ans) : -1
};

console.log(networkDelayTime([[1, 2, 1]], 2, 2))
// @lc code=end
