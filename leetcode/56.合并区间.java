
/*
* @lc app=leetcode.cn id=56 lang=java
*
* [56] 合并区间
*
* https://leetcode.cn/problems/merge-intervals/description/
*
* algorithms
* Medium (49.25%)
* Likes:    1815
* Dislikes: 0
* Total Accepted:    594.1K
* Total Submissions: 1.2M
* Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
*
* 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
* 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*
*
*
* 示例 1：
*
*
* 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
* 输出：[[1,6],[8,10],[15,18]]
* 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*
*
* 示例 2：
*
*
* 输入：intervals = [[1,4],[4,5]]
* 输出：[[1,5]]
* 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*
*
*
* 提示：
*
*
* 1 <= intervals.length <= 10^4
* intervals[i].length == 2
* 0 <= starti <= endi <= 10^4
*
*
*/

import java.util.Arrays;

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length == 0) {
            return new int[0][2];
        }
        if (intervals.length == 1) {
            return intervals;
        }
        Arrays.sort(intervals, (v1, v2) -> v1[0] - v2[0]);
        int[][] res = new int[intervals.length][2];
        int idx = 0, tmpl = intervals[0][0], tmpr = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (tmpr < intervals[i][0]) {
                res[idx][0] = tmpl;
                res[idx++][1] = tmpr;
                tmpl = intervals[i][0];
                tmpr = intervals[i][1];
            } else {
                tmpr = Math.max(tmpr, intervals[i][1]);
            }
        }
        res[idx][0] = tmpl;
        res[idx++][1] = tmpr;
        return Arrays.copyOf(res, idx);
    }

    public static void main(String[] args) {
        System.out.println(111);
    }
}
// @lc code=end
