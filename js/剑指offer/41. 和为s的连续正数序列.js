/**
 * 
 * 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 */
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function (target) {
  let res = []
  for (let l = 1, r = 2; l < r;) {
    // l+r 首项+末项，r-l+1是项数
    let sum = (l + r) * (r - l + 1) / 2
    if (sum == target) {
      //有点妙，
      let tmp = (new Array(r - l + 1)).fill(0).map((v, index) => l + index);
      res.push(tmp)
      l++
    } else if (sum < target) {
      r++
    } else {
      l++
    };
  }
  return res;
};