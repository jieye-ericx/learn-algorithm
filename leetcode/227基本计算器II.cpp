/* 
实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:
输入: "3+2*2"
输出: 7
示例 2:
输入: " 3/2 "
输出: 1
示例 3:
输入: " 3+5 / 2 "
输出: 5
 */
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
int calculate(string s);
int main()
{

    calculate(" 3+5 / 2 ");
    return 0;
}
int calculate(string s)
{
    int i, tmp = 0, ans = 0;
    stack<int> ss1, ss2;
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
            }
            // 抵消for循环的i++
            i--;
            // cout << tmp << endl;
            ss1.push(tmp);
        }
        else
        {
            switch (s[i])
            {
            case '+':

                break;
            case '-':

                break;
            case '*':
                int num1 = ss1.top();
                ss1.pop();
                break;
            case '/':

                break;

            default:
                break;
            }
        }
    }
}