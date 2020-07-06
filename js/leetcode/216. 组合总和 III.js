/**
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
 */
/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function (k, n) {
  if (n > 45) return []
  let ans = [],
    vis = Array(10).fill(0),
    tmp = [],
    dfs = (dep, rest) => {
      // console.log("dep " + dep + " re " + rest);
      // 剪枝
      if (rest > (19 - dep) * dep / 2) {
        return
      }
      if (dep === 0) {
        // const nowValStr = JSON.stringify(tmp.sort((a, b) => a - b))
        // 注意不能像上面这样写，因为tmp.sort是原地操作，会打乱tmp的顺序导致结果出错
        let nowArr = Array.from(tmp)
        const nowValStr = JSON.stringify(nowArr.sort((a, b) => a - b))
        if (rest === 0 && ans.findIndex(ele => JSON.stringify(ele) === nowValStr) === -1) {
          ans.push(JSON.parse(nowValStr))
        }
        return
      }
      for (let i = 1; i <= 9 && i <= rest; i++) {
        if (vis[i] === 0) {
          vis[i] = 1
          tmp.push(i)
          dfs(dep - 1, rest - i)
          vis[i] = 0
          tmp.pop()
        }
      }
    }

  dfs(k, n)
  return ans
};

console.log(combinationSum3(3, 7));
