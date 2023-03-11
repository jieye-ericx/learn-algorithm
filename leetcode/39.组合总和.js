/**
 * 39. 组合总和
candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function (candidates, target) {
  candidates.sort((a, b) => a > b);
  let tmpArr = [],
    ans = [];
  let dfs = () => {
    const nowVal = tmpArr.reduce((pri, cur, ind, arr) => pri + cur, 0);
    if (nowVal > target) {
      return;
    } else if (nowVal === target) {
      const outArr = Array.from(tmpArr).sort((a, b) => a - b);
      const out = JSON.stringify(outArr);
      if (!ans.some((arr) => JSON.stringify(arr) === out)) {
        ans.push(outArr);
      }
      return;
    }
    // let ptr = candidates.findIndex(ele => ele >= (target - nowVal))
    for (let ptr = 0; candidates[ptr] <= target - nowVal; ptr++) {
      tmpArr.push(candidates[ptr]);
      dfs();
      tmpArr.pop();
    }
  };
  dfs();
  // console.log(ans)
  return ans;
};

console.log(combinationSum([8, 7, 4, 3], 11));
console.log(combinationSum([2, 3, 5], 8));
