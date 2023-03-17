/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 *
 * https://leetcode.cn/problems/maximal-network-rank/description/
 *
 * algorithms
 * Medium (56.99%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 28.7K
 * Testcase Example:  '4\n[[0,1],[0,3],[1,2],[1,3]]'
 *
 * n 座城市和一些连接这些城市的道路 roads 共同组成一个基础设施网络。每个 roads[i] = [ai, bi] 都表示在城市 ai 和 bi
 * 之间有一条双向道路。
 *
 * 两座不同城市构成的 城市对 的 网络秩 定义为：与这两座城市 直接 相连的道路总数。如果存在一条道路直接连接这两座城市，则这条道路只计算 一次 。
 *
 * 整个基础设施网络的 最大网络秩 是所有不同城市对中的 最大网络秩 。
 *
 * 给你整数 n 和数组 roads，返回整个基础设施网络的 最大网络秩 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
 * 输出：4
 * 解释：城市 0 和 1 的网络秩是 4，因为共有 4 条道路与城市 0 或 1 相连。位于 0 和 1 之间的道路只计算一次。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
 * 输出：5
 * 解释：共有 5 条道路与城市 1 或 2 相连。
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
 * 输出：5
 * 解释：2 和 5 的网络秩为 5，注意并非所有的城市都需要连接起来。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2
 * 0
 * roads[i].length == 2
 * 0 i, bi 
 * ai != bi
 * 每对城市之间 最多只有一条 道路相连
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
#include <list>
#include <set>
using namespace std;

int main()
{

    return 0;
}

// @lc code=start
class Solution
{
public:
    struct Edge
    {
        int a, b, cost;
        bool operator<(const Edge &A) const
        {
            return cost < A.cost;
        }
    };
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        if (roads.size() == 0)
            return 0;
        vector<map<int, int>> r(n, map<int, int>{});
        int Lans = 0, tmp = 0;
        for (auto c : roads)
        {
            r[c[0]][c[1]] = c[0];
            r[c[1]][c[0]] = c[1];
        }
        sort(r.begin(), r.end(), cmp);
        int cnt = 0, i = 0;
        while (i < r.size() - 1 && r[i].size() == r[i + 1].size())
        {
            i++;
        }
        cnt = i + 1;
        while (cnt < r.size() - 1 && r[cnt].size() == r[cnt + 1].size())
        {
            cnt++;
        }
        for (int j = 0; j < r.size() && j <= i; j++)
        {
            for (int k = j + 1; k < r.size() && k <= cnt; k++)
            {
                // cout << r[j].begin()->second << " " << r[k].begin()->second << endl;
                tmp = r[j].size() + r[k].size();
                if (r[j].count(r[k].begin()->second) > 0)
                    tmp--;
                // cout << j << " " << k << endl;
                Lans = max(tmp, Lans);
            }
        }

        return Lans;
    };
    static bool cmp(map<int, int> a, map<int, int> b)
    {
        return a.size() > b.size();
    }
};
// @lc code=end
