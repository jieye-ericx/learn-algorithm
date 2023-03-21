/**
 *
 * 现在小美获得了一个字符串。小美想要使得这个字符串是回文串。
小美找到了你。你可以将字符串中至多两个位置改为任意小写英文字符’a’-‘z’。
你的任务是帮助小美在当前制约下，获得字典序最小的回文字符串。
数据保证能在题目限制下形成回文字符串。
注：回文字符串：即一个字符串从前向后和从后向前是完全一致的字符串。
例如字符串abcba, aaaa, acca都是回文字符串。字符串abcd, acea都不是回文字符串。
输入描述
一行，一个字符串。字符串中仅由小写英文字符构成。
保证字符串不会是空字符串。
字符串长度介于 [1, 100000] 之间。
输出描述
一行，一个在题目条件限制下所可以获得的字典序最小的回文字符串。
样例输入
acca
样例输出
aaaa
提示
样例解释1
原来的字符串已经是回文字符串了。但它不是题目条件下可以取得的字典序最小的回文字符串。将第二个字符和第三个字符都改为a可以获得字典序最小的回文字符串。
输入样例2
abcde
输出样例2
abcba
样例解释2
将de改为ba可以获得字典序最小的回文字符串。
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

string s;
bool isHuiwen(int n)
{
  for (int i = 0, j = n - 1; i < j; i++, j--)
  {
    if (s[i] != s[j])
    {
      return false;
    }
  }
  return true;
}
int main()
{
  while (cin >> s)
  {
    int n = s.size();
    // cout << n << endl;
    if (isHuiwen(n))
    {
      for (int i = 0, j = n - 1; i < j; i++, j--)
      {
        if (s[i] != 'a')
        {
          s[i] = 'a';
          s[j] = 'a';
          break;
        }
      }
    }
    else
    {
    }
    cout << s << endl;
  }

  return 0;
}
