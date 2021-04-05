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
bool isOp(char a);
string midTransLast(string s);  //仅支持个位数字或字母中缀转后缀
int calLastE(vector<string> s); //!通用后缀计算
int calculate(string s);
int calculateE(string s);
vector<string> midTransLastE(string s); //!通用中缀转后缀
int main()
{
  // cout << midTransLast("a+b-a*((c+d)/e-f)+g") << endl;
  // vector<string> aa = midTransLastE("a+b-a*((c+d)/e-f)+g");
  // for (int i = 0; i < aa.size(); i++)
  // {
  //     cout << aa[i] << " ";
  // }
  // cout << endl;
  // ---------------------------------------------
  // cout << midTransLast("3+22*2") << endl;
  // vector<string> aa = midTransLastE("3+22*2");
  // for (int i = 0; i < aa.size(); i++)
  // {
  //     cout << aa[i] << " ";
  // }
  // cout << endl;

  // cout << calculate(midTransLast("3 + 5 / 2")) << endl;
  // cout << calculate(midTransLast("3 / 2")) << endl;
  // cout << calculate(midTransLast("3 + 2*   2")) << endl;
  // cout << calculate(midTransLast("321")) << endl;

  cout << calculateE("3 + 5 / 2") << endl;
  cout << calculateE("31 / 2") << endl;
  cout << calculateE("323 + 2231*   2") << endl;
  cout << calculateE("321") << endl;
  // calculate(" 3+5 / 2 ");
  return 0;
}
int calculateE(string s)
{
  // 先把s转成后缀
  vector<string> ss = midTransLastE(s);
  // for (int i = 0; i < ss.size(); i++)
  // {
  //     cout << ss[i] << " ";
  // }
  // cout << endl;

  return calLastE(ss);
}
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

// 多位数字加强版
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
    if (s[i] == ' ') //过滤空格
      continue;
    if (!isOp(s[i]))
    { //是数字的话就遍历所有位数并直接输出
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
        //注意while结束后可能会因为isp[ss.top()] == icp[s[i]]，即出现括号导致（无法出栈；
        if (isp[ss.top()] == icp[s[i]] && ss.top() == '(')
          ss.pop();
        ss.push(s[i]);
      }
    }
  }
  return ans;
}
bool isOp(char a)
{
  return a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')' || a == '#';
}

//! 中缀转后缀 字母变量或个位数算式可用 整个下面都是旧版本

string midTransLast(string s)
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
  string ans = "";
  stack<char> ss;
  ss.push(s[0]);
  for (int i = 1; i < s.size(); i++)
  {
    if (s[i] == ' ') //过滤空格
      continue;
    if (!isOp(s[i]))
    {
      // 操作数直接输出,对于多位数字，确实会出错
      ans += s[i];
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
            ans += ss.top();
          }
          ss.pop();
        }
        //注意while结束后可能会因为isp[ss.top()] == icp[s[i]]，即出现括号导致（无法出栈；
        if (isp[ss.top()] == icp[s[i]] && ss.top() == '(')
          ss.pop();
        ss.push(s[i]);
      }
    }
  }
  return ans;
}

int calLast(string s)
{
  stack<int> ss;
  for (int i = 0; i < s.size(); i++)
  {
    if (isOp(s[i]))
    {
      int a = ss.top(), c;
      ss.pop();
      int b = ss.top();
      ss.pop();
      switch (s[i])
      {
      case '+':
        c = b + a;
        break;
      case '-':
        c = b - a;
        break;
      case '*':
        c = b * a;
        break;
      case '/':
        c = b / a;
        break;

      default:
        break;
      }
      ss.push(c);
    }
    else
    {
      int tmp = s[i++] - '0';
      while (i < s.size() && !isOp(s[i++]))
      {
        tmp = tmp * 10 + (s[i] - '0');
      }
      i--;
      ss.push(tmp);
    }
  }
  return ss.top();
}