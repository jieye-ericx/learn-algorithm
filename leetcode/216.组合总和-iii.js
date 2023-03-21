/*
 * @lc app=leetcode.cn id=216 lang=javascript
 *
 * [216] 组合总和 III
 *
 * https://leetcode.cn/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.94%)
 * Likes:    641
 * Dislikes: 0
 * Total Accepted:    243.6K
 * Total Submissions: 338.9K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
 *
 *
 * 只使用数字1到9
 * 每个数字 最多使用一次
 *
 *
 * 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 解释:
 * 1 + 2 + 4 = 7
 * 没有其他符合的组合了。
 *
 * 示例 2:
 *
 *
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 解释:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * 没有其他符合的组合了。
 *
 * 示例 3:
 *
 *
 * 输入: k = 4, n = 1
 * 输出: []
 * 解释: 不存在有效的组合。
 * 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 60
 *
 *
 */

// @lc code=start
/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function (k, n) {
  if (n > 45) return [];
  let ans = [],
    vis = Array(10).fill(0),
    tmp = [],
    dfs = (dep, rest) => {
      // console.log("dep " + dep + " re " + rest);
      // 剪枝
      if (rest > ((19 - dep) * dep) / 2) {
        return;
      }
      if (dep === 0) {
        // const nowValStr = JSON.stringify(tmp.sort((a, b) => a - b))
        // 注意不能像上面这样写，因为tmp.sort是原地操作，会打乱tmp的顺序导致结果出错
        let nowArr = Array.from(tmp);
        const nowValStr = JSON.stringify(nowArr.sort((a, b) => a - b));
        if (
          rest === 0 &&
          ans.findIndex((ele) => JSON.stringify(ele) === nowValStr) === -1
        ) {
          ans.push(JSON.parse(nowValStr));
        }
        return;
      }
      for (let i = 1; i <= 9 && i <= rest; i++) {
        if (vis[i] === 0) {
          vis[i] = 1;
          tmp.push(i);
          dfs(dep - 1, rest - i);
          vis[i] = 0;
          tmp.pop();
        }
      }
    };

  dfs(k, n);
  return ans;
};
// @lc code=end
