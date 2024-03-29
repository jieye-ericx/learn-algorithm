/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (52.41%)
 * Likes:    971
 * Dislikes: 0
 * Total Accepted:    127K
 * Total Submissions: 242.4K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
 *
 * 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 *
 * 题目数据保证答案符合 32 位带符号整数范围。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 *
 * 示例 2：
 *
 *
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s 和 t 由英文字母组成
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

// @lc code=start
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        s = " " + s;
        t = " " + t;
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;
        // dp[i][j]表示s[1...i],t[1...j]的种数

        vector<vector<unsigned long long>> dp(m, vector<unsigned long long>(n, 0));
        for (int i = 0; i < m; i++)
        {
            // 空字符串是任何字符串的子序列
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j <= i && j < n; j++)
            {
                if (s[i] == t[j])
                {
                    // dp[i - 1][j - 1]表示将s[i]和t[j]进行绑定
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// int main()
// {
//     Solution s;
//     s.numDistinct("rabbbit", "rabbit");
//     return 0;
// }
// @lc code=end
