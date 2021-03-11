/* 实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。
示例 1：
输入：s = "1 + 1"
输出：2
示例 2：
输入：s = " 2-1 + 2 "
输出：3
示例 3：
输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
 */
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
// !我的想法是用传统的转换成后缀再计算比较通用
int calculate(string s)
{
    int i, tmp = 0, ans = 0, sign = 1;
    stack<int> ss;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (s[i] >= '0')
        {
            tmp = s[i++] - '0';
            while (s[i] >= '0')
            {
                tmp *= 10;
                tmp += s[i] - '0';
                i++;
            }
            // 抵消for循环的i++
            i--;
            // cout << tmp << endl;
            ans += sign * tmp;
        }
        else if (s[i] == '+')
        {
            sign = 1;
        }
        else if (s[i] == '-')
        {
            sign = -1;
        }
        else if (s[i] == '(')
        {
            ss.push(ans);
            ss.push(sign);
            ans = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            ans *= ss.top();
            ss.pop();
            ans += ss.top();
            ss.pop();
        }
    }
    return ans;
}