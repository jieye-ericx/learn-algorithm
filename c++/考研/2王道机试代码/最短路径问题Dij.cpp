/* 题目描述
给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的。
输入描述:
输入n,m，点的编号是1~n,然后是m行，每行4个数 a,b,d,p，表示a和b之间有一条边，且其长度为d，花费为p。最后一行是两个数 s,t;起点s，终点t。n和m为0时输入结束。
(1<n<=1000, 0<m<100000, s != t)
输出描述:
输出 一行有两个数， 最短距离及其花费。
示例1
输入
复制
3 2
1 2 5 6
2 3 4 5
1 3
0 0
输出
复制
9 11 */
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
const int N = 1002;
int n, m, a, b, d, p, s, t;
struct edge
{
  int to, len, w;
  edge(int to, int len, int w) : to(to), len(len), w(w) {}
};
struct po
{
  int num, dis;
  po(int num, int dis) : num(num), dis(dis) {}
  bool operator<(const po &p) const
  {
    return dis < p.dis;
  }
};
vector<edge> g[N];
int dis[N], cost[N];
void dij(int st)
{
  priority_queue<po> que;
  dis[st] = 0;
  cost[st] = 0;
  que.push(po(st, 0));
  //将初始点推入优先队列
  while (!que.empty())
  {
    po pp = que.top();
    que.pop();
    // 遍历当前结点的所有邻点，
    for (int i = 0; i < g[pp.num].size(); i++)
    {
      int v = g[pp.num][i].to;
      int l = g[pp.num][i].len;
      int w = g[pp.num][i].w;
      // cout << v << " " << l << " " << w << endl;
      // 如果起点st到顶点v的距离大于起点st先到达顶点pp.num再到v的距离，则替换
      if (dis[v] > dis[pp.num] + l || (dis[v] == dis[pp.num] + l && cost[v] > cost[pp.num] + w))
      {
        dis[v] = dis[pp.num] + l;
        cost[v] = cost[pp.num] + w;
        que.push(po(v, dis[v]));
      }
    }
  }
}
int main()
{
  while (scanf("%d%d", &n, &m) != EOF && n != 0)
  {
    fill(dis, dis + n + 1, INT32_MAX);
    fill(cost, cost + n + 1, INT32_MAX);
    memset(g, 0, sizeof(g));
    for (int i = 0; i < m; i++)
    {
      scanf("%d%d%d%d", &a, &b, &d, &p);
      g[a].push_back(edge(b, d, p));
      g[b].push_back(edge(a, d, p));
    }
    scanf("%d%d", &s, &t);
    dij(s);
    printf("%d %d\n", dis[t], cost[t]);
  }
  return 0;
}
