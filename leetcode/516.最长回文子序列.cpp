/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode.cn/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (67.15%)
 * Likes:    967
 * Dislikes: 0
 * Total Accepted:    169.2K
 * Total Submissions: 251.9K
 * Testcase Example:  '"bbbab"'
 *
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 *
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string ss = s;
        reverse(ss.begin(), ss.end());
        int l = longestCommonSubsequence(s, ss);
        return l;
    }
    int longestCommonSubsequence(string t1, string t2)
    {
        int dp[t1.size() + 1][t2.size() + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < t1.size() + 1; i++)
        {
            for (int j = 1; j < t2.size() + 1; j++)
            {
                if (t1[i - 1] == t2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[t1.size()][t2.size()];
    }
};
// @lc code=end
