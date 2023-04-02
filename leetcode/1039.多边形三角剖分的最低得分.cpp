/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 *
 * https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/description/
 *
 * algorithms
 * Medium (57.43%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    12K
 * Total Submissions: 19.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 你有一个凸的 n 边形，其每个顶点都有一个整数值。给定一个整数数组 values ，其中 values[i] 是第 i 个顶点的值（即 顺时针顺序
 * ）。
 *
 * 假设将多边形 剖分 为 n - 2 个三角形。对于每个三角形，该三角形的值是顶点标记的乘积，三角剖分的分数是进行三角剖分后所有 n - 2
 * 个三角形的值之和。
 *
 * 返回 多边形进行三角剖分后可以得到的最低分 。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：values = [1,2,3]
 * 输出：6
 * 解释：多边形已经三角化，唯一三角形的分数为 6。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：values = [3,7,4,5]
 * 输出：144
 * 解释：有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7 = 144。最低分数为 144。
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：values = [1,3,1,4,1,5]
 * 输出：13
 * 解释：最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == values.length
 * 3 <= n <= 50
 * 1 <= values[i] <= 100
 *
 *
 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;
#define debug(a) cout << #a << "=" << a << endl;
#define lyh(i, a, b) for (int i = a; i <= b; i++)
#define hyl(i, a, b) for (int i = a; i >= b; i--)
#define LL long long

int main()
{

    return 0;
}

// @lc code=start
// ! 一个是递归写法一个是递归转成动态规划
// class Solution
// {
// private:
//     vector<vector<int>> v;

// public:
//     int minScoreTriangulation(vector<int> &values)
//     {
//         v = vector<vector<int>>(50, vector<int>(50, -1));
//         return dfs(0, values.size() - 1, values);
//     }
//     int dfs(int i, int j, vector<int> &values)
//     {
//         if (i + 1 == j)
//         {
//             return 0;
//         }
//         int res = __INT32_MAX__;
//         for (int k = i + 1; k < j; k++)
//         {
//             res = min(res, (this->v[i][k] != -1 ? this->v[i][k] : dfs(i, k, values)) + (this->v[k][j] != -1 ? this->v[k][j] : dfs(k, j, values)) + values[i] * values[k] * values[j]);
//         }
//         this->v[i][j] = res;
//         return res;
//     }
// };
class Solution
{
private:
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = n - 3; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int res = INT32_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    res = min(res, dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
                dp[i][j] = res;
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end
