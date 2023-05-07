/*

服务器有三种运行状态：空载、单任务、多任务，每个时间片的能耗的分别为1、3、 4;
每个任务由起始时间片和结束时间片定义运行时间；
如果一个时问片只有一个任务需要执行，则服务器处于单任务状态；
如果一个时间片有多个任务需要执行，则服务器处于多任务状态；
给定一个任务列表，请计算出从第一个任务开始，到所有任务结束，服务器的总能耗。
输入
第一行的数字表示一共有多少个任务
后续每行包含由空格分割的两个整数，用于确定每一个任务的起始时间片和结束时间片；任务执行时间包含起始和结束时间片，即任务执行时间是左闭右闭的；
结束时间片一定大于等于起始时间片；
输出
一个整数，代表服务器的总能耗

例如：
2
2 5
8 9
应该输出20
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
#define LL long long
using namespace std;

int main()
{
  LL ans = 0;
  int n, start_time, end_time;
  cin >> n;
  vector<pair<int, int>> tasks(n), cur_tasks;
  cin >> tasks[0].first >> tasks[0].second;
  start_time = tasks[0].first;
  end_time = tasks[0].second;
  for (int i = 1; i < n; i++)
  {
    cin >> tasks[i].first >> tasks[i].second;
    end_time = max(end_time, tasks[i].second);
    start_time = min(start_time, tasks[i].first);
  }
  int nn = end_time - start_time + 2;
  vector<int> a(nn, 0);
  for (auto t : tasks)
  {
    a[t.first - start_time]++;
    a[t.second - start_time + 1]--;
  }
  for (int i = 1; i < a.size(); i++)
  {
    a[i] += a[i - 1];
  }
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] == 0)
    {
      ans += 1;
    }
    else if (a[i] == 1)
    {
      ans += 3;
    }
    else
    {

      ans += 4;
    }
  }

  cout << ans - 1 << endl;
  return 0;
}
