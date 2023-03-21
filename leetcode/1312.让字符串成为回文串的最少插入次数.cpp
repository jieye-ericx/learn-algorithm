/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 *
 * https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (68.76%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 32.7K
 * Testcase Example:  '"zzazz"'
 *
 * 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
 *
 * 请你返回让 s 成为回文串的 最少操作次数 。
 *
 * 「回文串」是正读和反读都相同的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "zzazz"
 * 输出：0
 * 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "mbadm"
 * 输出：2
 * 解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "leetcode"
 * 输出：5
 * 解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 中所有字符都是小写字母。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minInsertions(string s)
    {
        string ss = s;
        reverse(ss.begin(), ss.end());
        int l = longestCommonSubsequence(s, ss);
        return s.size() - l;
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
