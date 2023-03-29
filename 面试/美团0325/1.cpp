/**
 *
 * 小美是一个火车迷。最近她在观察家附近火车站的火车驶入和驶出情况，发现火车驶入和驶出的顺序并不一致。经过小美调查发现，原来这个火车站里面有一个类似于栈的结构，如下图所示：



例如可能1号火车驶入了火车站中的休息区s，在驶出之前2号火车驶入了。那么在这种情况下，1号火车需要等待2号火车倒车出去后才能出去（显然被后面驶入的2号火车挡住了，这个休息区s只有一个出入口）。

出于好奇，小美统计了近些天的火车驶入驶出情况，开始统计和结束统计时休息区s中均是空的。由于中途疏忽，小美觉得自己好像弄错了几个驶入驶出顺序，想请你帮她验证一下。值得注意的是，小美虽然可能弄错了顺序，但对火车的记录是不重不漏的。

形式化地来形容休息区s，我们视其为一个容量无限大的空间，假设两列火车 i 和 j 同时处于休息区s中，驶入时刻Tin满足Tin(i)<Tin(j)，则驶出时间Tout必定满足Tout(i)>Tout(j)，即，先进后出。

输入描述
第一行一个整数T表示数据组数。

对每组测试而言：
第一行一个整数n，表示观察到的火车数量。
第二行n个整数x1,x2,...,xn，表示小美记录的火车驶入休息区s的顺序。
第三行n个整数y1,y2,...,yn，表示小美记录的火车驶出休息区s的顺序。
1≤T≤10,1≤n≤50000,1≤xi,yi≤n, 且{xn} 、{yn} 均为{1,2,3,...,n}的一个排列，即1~n这n个数在其中不重不漏恰好出现一次。
输出描述
对每组数据输出一行：如果小美记录的驶入和驶出顺序无法被满足则输出No，否则输出Yes。
3
3
1 2 3
1 2 3
3
1 2 3
3 2 1
3
1 2 3
3 1 2
样例输出
Yes
Yes
No
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
#define debug(a) cout << #a << "=" << a << endl;
#define lyh(i, a, b) for (int i = a; i <= b; i++)
#define hyl(i, a, b) for (int i = a; i >= b; i--)
#define LL long long
int n, t;
vector<int> in, out;
bool IsOk()
{
  if (in.size() != out.size() || in.size() == 0 || out.size() == 0)
    return false;
  stack<int> s;
  int i = 0, j = 0;
  for (; i < in.size(); i++)
  {
    s.push(in[i]);
    while (s.size() != 0 && s.top() == out[j])
    {
      s.pop();
      j++;
    }
  }
  return s.empty() && i == j;
}
int main()
{
  cin >> t;
  while (t--)
  {
    cin >> n;
    in = vector<int>(n, 0);
    out = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
      cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> out[i];
    }
    if (IsOk())
      cout << "Yes\n";
    else
      cout << "No\n";
    // for (int i = 0; i < n; i++)
    // {
    //   cout << in[i] << " ";
    // }
    // for (int i = 0; i < n; i++)
    // {
    //   cout << out[i] << " ";
    // }
  }

  return 0;
}
