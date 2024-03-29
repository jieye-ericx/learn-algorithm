/* 题目描述
    省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，
    只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，
    以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
输入描述:
    测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；
    随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），
    此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。
    当N为0时输入结束。
输出描述:
    每个测试用例的输出占一行，输出全省畅通需要的最低成本。
示例1
输入
复制
3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0
输出
3
1
0
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
const int N = 102;
int n, ans;
struct ed
{
  int from, to, w, ok;
} eds[N * N];
bool tmp(ed e1, ed e2)
{
  if (e1.ok != e2.ok)
    return e1.ok > e2.ok;
  return e1.w < e2.w;
}
int father[N], hei[N];
void init()
{
  for (int i = 0; i < N; i++)
  {
    father[i] = i;
    hei[i] = 0;
  }
}
int find(int x)
{
  if (x != father[x])
  {
    father[x] = find(father[x]);
  }
  return father[x];
}
void uni(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x != y)
  {
    if (hei[x] < hei[y])
    {
      father[x] = y;
    }
    else if (hei[x] > hei[y])
    {
      father[y] = x;
    }
    else
    {
      father[x] = y;
      hei[y]++;
    }
  }
}

int main()
{
  while (scanf("%d", &n) != EOF && n != 0)
  {
    init();
    int en = n * (n - 1) / 2, ans = 0;
    for (int i = 0; i < en; i++)
    {
      scanf("%d%d%d%d", &eds[i].from, &eds[i].to, &eds[i].w, &eds[i].ok);
    }
    sort(eds, eds + en, tmp);
    for (int i = 0; i < en; i++)
    {
      if (find(eds[i].from) != find(eds[i].to))
      {
        uni(eds[i].from, eds[i].to);
        ans += eds[i].ok == 1 ? 0 : eds[i].w;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
