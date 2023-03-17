/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode.cn/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (59.10%)
 * Likes:    2105
 * Dislikes: 0
 * Total Accepted:    621.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 *
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 *
 * 此外，你可以假设该网格的四条边均被水包围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1
 * grid[i][j] 的值为 '0' 或 '1'
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

// @lc code=start
class Solution
{
public:
    int M, N;
    vector<vector<int>> vis;
    vector<vector<char>> grid;

    bool is_valid(int x, int y)
    {
        return (x >= 0 && x < M && y >= 0 && y < N && !vis[x][y] && grid[x][y] == '1');
    }

    void dfs(int x, int y)
    {
        vis[x][y] = 1;
        int dx, dy;
        for (int i = 0; i < 4; i++)
        {
            dx = x + dir[i][0];
            dy = y + dir[i][1];
            if (is_valid(dx, dy))
            {
                dfs(dx, dy);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        this->grid = grid;
        M = grid.size();
        N = grid[0].size();
        vis = vector<vector<int>>(M, vector<int>(N, 0));

        int island_cnt = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(i, j);
                    island_cnt++;
                }
            }
        }
        return island_cnt;
    }

private:
    const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};

// 我的代码超时了，我让chatgpt帮忙修改了一下，然后就过了，上面的是他的
class Solution
{
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int M, N;
    vector<vector<int>> vis;
    vector<vector<int>> func;
    vector<vector<char>> arr;
    bool ok(int x, int y)
    {
        //
        if (arr[x][y] == '0')
        {
            return false;
        }
        //
        if (x < 0 || x >= M || y < 0 || y >= N || vis[x][y])
            return false;
        return true;
    }
    void dfs(int x, int y)
    {
        func[x][y] = 1;
        cout << x << " " << y << endl;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (ok(dx, dy))
            {

                vis[dx][dy] = 1;
                dfs(dx, dy);
                vis[dx][dy] = 0;
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        arr = grid;
        M = arr.size();
        N = arr[0].size();
        vis = vector<vector<int>>(M, vector<int>(N, 0));
        func = vector<vector<int>>(M, vector<int>(N, 0));
        int ans = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                cout << i << " ij " << j << endl;
                if (arr[i][j] == '1' && func[i][j] == 0)
                {
                    ans++;
                    dfs(i, j);
                }
            }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution s;
    s.numIslands()
}