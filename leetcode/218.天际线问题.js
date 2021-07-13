/*
 * @lc app=leetcode.cn id=218 lang=javascript
 *
 * [218] 天际线问题
 *
 * https://leetcode-cn.com/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (51.55%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    22.9K
 * Total Submissions: 44.5K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * 城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回由这些建筑物形成的 天际线 。
 *
 * 每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti]
 * 表示：
 *
 *
 * lefti 是第 i 座建筑物左边缘的 x 坐标。
 * righti 是第 i 座建筑物右边缘的 x 坐标。
 * heighti 是第 i 座建筑物的高度。
 *
 *
 * 天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序
 * 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0
 * ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
 *
 * 注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...]
 * 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
 * 输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
 * 解释：
 * 图 A 显示输入的所有建筑物的位置和高度，
 * 图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。
 *
 * 示例 2：
 *
 *
 * 输入：buildings = [[0,2,3],[2,5,3]]
 * 输出：[[0,3],[5,0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 0 i < righti
 * 1 i
 * buildings 按 lefti 非递减排序
 *
 *
 */

// @lc code=start
/**
 * @param {number[][]} buildings
 * @return {number[][]}
 */
var getSkyline = function (buildings) {
  let ans = [];
  let arr = [];

  // 将一个建筑分为两部分，一个是左端点 + 负的高度，另一个是右端点 + 高度
  for (let [l, r, h] of buildings) {
    arr.push([l, -h]);
    arr.push([r, h]);
  }

  let heights = [0];  // 最低高度

  // 根据横坐标从小到大排序，若横坐标相等，则按高度从小到大排序
  // 注意，对于两个横坐标都相等的左端点，因为保存的是负的高度，因此实际更高的左端点会被排在前面
  arr.sort((a, b) => a[0] !== b[0] ? a[0] - b[0] : a[1] - b[1]);

  // 使用一个变量记录前一个存入结果中的高度，因为不能存入高度相同的点
  let pre = null;
  // ! heights可以理解为最大堆，见80行，其中初始包含0是考虑到有建筑物相邻的情况，则需要有（x，0）
  for (let [l, h] of arr) {
    // 左端点
    if (h < 0) {
      heights.push(-h);
    } else { // 右端点，将高度从 Heights 中移除
      let idx = heights.indexOf(h);
      heights.splice(idx, 1);
    }

    let maxh = Math.max(...heights);

    if (!pre) {
      ans.push([l, maxh]);
    } else if (pre !== maxh) {
      // !可以跳过右端点
      ans.push([l, maxh]);
    }
    pre = maxh;
  }

  return ans;
};
// @lc code=end

