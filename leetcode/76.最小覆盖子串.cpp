/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (45.10%)
 * Likes:    2343
 * Dislikes: 0
 * Total Accepted:    389K
 * Total Submissions: 862.3K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 *
 *
 *
 * 注意：
 *
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 *
 *
 *
 * 提示：
 *
 *
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 *
 *
 *
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <list>
using namespace std;

// !基于比较ans和t的方法会超时
// @lc code=start
class Solution
{
public:
    // 附上大佬代码
    string minWindow(string s, string t)
    {
        vector<int> map(128, 0);
        for (auto c : t)
            map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size())
        {
            if (map[s[end++]]-- > 0)
                counter--; // in t
            while (counter == 0)
            { // valid
                if (end - begin < d)
                    d = end - (head = begin);
                if (map[s[begin++]]++ == 0)
                    counter++; // make it invalid
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
    //
    string minWindow(string s, string t)
    {
        map<char, int> mt, ans;
        int ansI = 1000000;
        string ansS("");
        for (int i = 0; i < t.size(); i++)
        {
            mt[t[i]]++;
        }

        int start = 0, end = 0;
        while (start <= end)
        {
            // cout << "start" << start << " " << end << endl;
            // cout << "start " << start << " " << end << " " << ansI << endl;
            while (!check(mt) && end < s.size())
            {
                if (mt.count(s[end]) > 0)
                {
                    mt[s[end]]--;
                }
                end++;
            }
            // if (!check(mt) && end == s.size())
            // {
            //     break;
            // }
            // if (check(mt) && end - start <= ansI)
            // {
            //     ansS = s.substr(start, end - start);
            //     ansI = end - start;
            // }
            while (start < s.size() && (mt.count(s[start]) == 0 || mt[s[start]] < 0))
            {
                if (mt.count(s[start]) == 1)
                {
                    mt[s[start]]++;
                }
                start++;
            }
            // ! 终于写的只需要判断一次结果的代码
            if (check(mt) && end - start <= ansI)
            {
                ansS = s.substr(start, end - start);
                ansI = end - start;
            }
            mt[s[start]]++;
            start++;
        }
        // cout << "start " << start << " " << end << " " << ansI << endl;
        return ansS;
    }
    bool check(map<char, int> m2)
    {
        for (auto m : m2)
        {
            if (m.second > 0)
            {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end
