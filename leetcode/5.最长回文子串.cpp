/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.44%)
 * Likes:    6280
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.6M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
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
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string ans = "";
        ans += s[0];
        vector<vector<int>> dp(n, vector<int>(n, true));
        // !使用dp判断s[i-j]是否是回文
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                // !虽然理论上i越小j越大越好，但需要判断下新j - i + 1（ans的长度）是否大于现有的
                if (dp[i][j] == 1 && (j - i + 1) >= ans.size())
                {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
        //! 如果只需要求最长回文串的长度，可以参考第1143
    }
};
// @lc code=end
