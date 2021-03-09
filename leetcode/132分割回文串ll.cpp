#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main()
{

    return 0;
}
/* 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
返回符合要求的 最少分割次数 
示例 1：
输入：s = "aab"
输出：1
解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 */
class Solution
{
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string &s, int i)
    {
        if (i == n)
        {
            ret.push_back(ans);
            return;
        }
        // 对于上一题，要求所有的可能，所以j从小到大
        // 本题要求最少分割次数，所以j从大到小比较合适
        for (int j = i; j < n; ++j)
        {
            if (f[i][j])
            {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    int minCut(string s)
    {
        n = s.size();
        f.assign(n, vector<int>(n, true));
        // !先利用dp预处理出整个s[i...j]是否是回文
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        int minx = 0xffffff;
        for (int i = 0; i < ret.size(); i++)
        {
            if (minx > ret[i].size())
            {
                minx = ret[i].size();
            }
        }
        return minx - 1;
    }
};
