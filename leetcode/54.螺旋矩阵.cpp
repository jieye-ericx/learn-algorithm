/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    1333
 * Dislikes: 0
 * Total Accepted:    351K
 * Total Submissions: 712.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1
 * -100
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <list>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int dir = 0; // 0向右，1向下，2向左，3向上
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int i = 0, j = 0;
        while (1)
        {
            while (i < m && j < n && i >= 0 && j >= 0 && vis[i][j] != 1)
            {
                vis[i][j] = 1;
                switch (dir)
                {
                case 0:
                    ans.emplace_back(matrix[i][j++]);
                    break;
                case 1:
                    ans.emplace_back(matrix[i++][j]);
                    break;
                case 2:
                    ans.emplace_back(matrix[i][j--]);
                    break;
                case 3:
                    ans.emplace_back(matrix[i--][j]);
                    break;
                }
            }
            // 第一次结束时i=0,j=n;
            switch (dir)
            {
            case 0:
                i++, j--;
                break;
            case 1:
                i--, j--;
                break;
            case 2:
                i--, j++;
                break;
            case 3:
                i++, j++;
                break;
            }
            if (i >= m || j >= n || j < 0 || i < 0 || vis[i][j])
            {
                return ans;
            }
            dir = (dir + 1) % 4;
        }
    }
};
// @lc code=end
