/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode.cn/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (44.46%)
 * Likes:    674
 * Dislikes: 0
 * Total Accepted:    143.8K
 * Total Submissions: 323.5K
 * Testcase Example:  '"3+2*2"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 *
 * 整数除法仅保留整数部分。
 *
 * 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2^31, 2^31 - 1] 的范围内。
 *
 * 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "3+2*2"
 * 输出：7
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = " 3/2 "
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = " 3+5 / 2 "
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
 * s 表示一个 有效表达式
 * 表达式中的所有整数都是非负整数，且在范围 [0, 2^31 - 1] 内
 * 题目数据保证答案是一个 32-bit 整数
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
#include <deque>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
bool isOp(char a);
string midTransLast(string s);  // 仅支持个位数字或字母中缀转后缀
int calLastE(vector<string> s); //! 通用后缀计算
int calculate(string s);
int calculateE(string s);
vector<string> midTransLastE(string s); //! 通用中缀转后缀

// 多位数字加强版

class Solution
{
public:
    int calculate(string s)
    {
        return calLastE(midTransLastE(s));
    }
    bool isOp(char a)
    {
        return a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')' || a == '#';
    }
    //! 通用后缀计算
    int calLastE(vector<string> s)
    {
        stack<int> ss;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/")
            {
                int a = ss.top(), c;
                ss.pop();
                int b = ss.top();
                ss.pop();
                if (s[i] == "+")
                {
                    c = b + a;
                }
                else if (s[i] == "-")
                {
                    c = b - a;
                }
                else if (s[i] == "*")
                {
                    c = b * a;
                }
                else
                {
                    c = b / a;
                }
                ss.push(c);
            }
            else
            {
                int tmp = stoi(s[i]);
                ss.push(tmp);
            }
        }
        return ss.top();
    }
    //! 通用中缀转后缀
    vector<string> midTransLastE(string s)
    {
        s = "#" + s + '#';
        map<char, int> isp;
        map<char, int> icp;
        isp['#'] = 0, icp['#'] = 0;
        isp['('] = 1, icp['('] = 6;
        isp['*'] = 5, icp['*'] = 4;
        isp['/'] = 5, icp['/'] = 4;
        isp['+'] = 3, icp['+'] = 2;
        isp['-'] = 3, icp['-'] = 2;
        isp[')'] = 6, icp[')'] = 1;
        // int isp[] = {0, 1, 5, 3, 6}; //#,( ,*/,+-,)
        // int icp[] = {0, 6, 4, 2, 1}; //#,( ,*/,+-,)
        vector<string> ans;
        stack<char> ss;
        ss.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ' ') // 过滤空格
                continue;
            if (!isOp(s[i]))
            { // 是数字的话就遍历所有位数并直接输出
                string tmp = "";
                while (i < s.size() && !isOp(s[i]))
                {
                    tmp += s[i];
                    i++;
                }
                i--;
                ans.push_back(tmp);
            }
            else
            {
                if (isp[ss.top()] < icp[s[i]])
                {
                    ss.push(s[i]);
                }
                else
                {
                    while (isp[ss.top()] > icp[s[i]])
                    {
                        if (!(ss.top() == '(' || ss.top() == ')' || ss.top() == '#'))
                        {
                            string a = "";
                            a += ss.top();
                            ans.push_back(a);
                        }
                        ss.pop();
                    }
                    // 注意while结束后可能会因为isp[ss.top()] == icp[s[i]]，即出现括号导致（无法出栈；
                    if (isp[ss.top()] == icp[s[i]] && ss.top() == '(')
                        ss.pop();
                    ss.push(s[i]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
