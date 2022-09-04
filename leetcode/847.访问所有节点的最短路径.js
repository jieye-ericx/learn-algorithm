/*
 * @lc app=leetcode.cn id=847 lang=javascript
 *
 * [847] 访问所有节点的最短路径
 *
 * https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/description/
 *
 * algorithms
 * Hard (67.92%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 28K
 * Testcase Example:  '[[1,2,3],[0],[0],[0]]'
 *
 * 存在一个由 n 个节点组成的无向连通图，图中的节点按从 0 到 n - 1 编号。
 *
 * 给你一个数组 graph 表示这个图。其中，graph[i] 是一个列表，由所有与节点 i 直接相连的节点组成。
 *
 * 返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：graph = [[1,2,3],[0],[0],[0]]
 * 输出：4
 * 解释：一种可能的路径为 [1,0,2,0,3]
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
 * 输出：4
 * 解释：一种可能的路径为 [0,1,4,2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == graph.length
 * 1 <= n <= 12
 * 0 <= graph[i].length < n
 * graph[i] 不包含 i
 * 如果 graph[a] 包含 b ，那么 graph[b] 也包含 a
 * 输入的图总是连通图
 *
 *
 */

// @lc code=start
/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function (graph) {
  const n = graph.length;
  // 初始化距离数组
  const dis = new Array(n).fill(0).map(() => new Array(n).fill(n + 1))
  // 输入直接可达节点的距离
  for (let i = 0; i < n; ++i) {
    for (const j of graph[i]) {
      dis[i][j] = 1;
    }
  }
  //Floyd算法预处理出所有点对之间的最短路径长度
  for (let k = 0; k < n; ++k) {
    for (let i = 0; i < n; ++i) {
      for (let j = 0; j < n; ++j) {
        dis[i][j] = Math.min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }

  // 初始化dp数组
  const dp = new Array(n).fill(0).map(() => new Array(1 << n).fill(Number.MAX_SAFE_INTEGER));
  // mask取值为1~2^n-1表示着n个节点的是否被访问的情况，从仅访问第一个节点到访问了所有节点
  for (let mask = 1; mask < (1 << n); ++mask) {
    // 如果mask的最高位只包含一个1，即 mask是2的幂，说明此时位于开始的节点，无法枚举满足要求的上一个关键节点v，初始化赋值为0即可
    if ((mask & (mask - 1)) === 0) {
      const tmp = (mask & (-mask)) - 1;
      // 求得此时mask所对应的开始节点u
      const u = tmp.toString(2).split('0').join('').length;
      // 初始化赋值
      dp[u][mask] = 0;
    } else {
      for (let u = 0; u < n; ++u) {
        // mask & (1 << u)用于检查节点u是否已经被访问过（即在mask中），如果访问过则跳过
        if ((mask & (1 << u)) !== 0) {
          for (let v = 0; v < n; ++v) {
            // 如果节点v被访问或和u时同一个节点，则跳过
            if ((mask & (1 << v)) !== 0 && u !== v) {
              // 按照第二部分得到的状态转移方程更新dp数组
              dp[u][mask] = Math.min(dp[u][mask], dp[v][mask ^ (1 << u)] + dis[v][u]);
            }
          }
        }
      }
    }
  }

  let ans = Number.MAX_SAFE_INTEGER;
  for (let u = 0; u < n; ++u) {
    ans = Math.min(ans, dp[u][(1 << n) - 1]);
  }
  return ans;
};

// @lc code=end
