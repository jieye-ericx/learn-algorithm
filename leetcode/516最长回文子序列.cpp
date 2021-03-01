/**
 * 建议看看更多关于回文子串的，我这里采取了通用写法，核心是longestCommonSubsequence
 * 求两个string的公共子串，那么要求回文子串，直接将s反转，然后求s和s反转的最大公共子串
*/

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
