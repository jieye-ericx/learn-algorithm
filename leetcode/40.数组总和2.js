/**
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
 */
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function (candidates, target) {
  candidates.sort((a, b) => a > b)
  var tmpArr = [],
    ans = [],
    vis = new Array(candidates.length).fill(0)
  var dfs = (arr, rest, tmp) => {
    if (rest < 0) {
      return
    } else if (rest === 0) {
      var outArr = [...Array.from(tmpArr).sort((a, b) => a - b)]
      var out = JSON.stringify(outArr)
      if (!arr.some((arr) => JSON.stringify(arr) === out)) {
        arr.push(outArr)
      }
      return
    }
    for (var ptr = 0; candidates[ptr] <= rest; ptr++) {
      if (vis[ptr] === 1) continue
      vis[ptr] = 1
      tmp.push(candidates[ptr])
      dfs(arr, rest - candidates[ptr], tmp)
      tmp.pop()
      vis[ptr] = 0
    }
  }
  dfs(ans, target, tmpArr)
  // console.log(ans)
    // dp
    let dp = Array([candidates.length]).fill(0)
    dp[1]
    for (let i = 2; i <= candidates.length; i++){
        for (let j = 1; j <= target; j++){
            dp[]
        }
    }
  return ans
}
console.log(combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
console.log(combinationSum2([2, 5, 2, 1, 2], 5))
