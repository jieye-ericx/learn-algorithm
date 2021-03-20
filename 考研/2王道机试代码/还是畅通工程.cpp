/* 
https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229?tpId=63&tqId=29595&tPage=2&rp=2&ru=%2Fta%2Fzju-kaoyan&tab=answerKey
题目描述
    某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。
    省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（
    但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。
输入描述:
    测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；
    随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，
    以及此两村庄间的距离。为简单起见，村庄从1到N编号。
    当N为0时，输入结束，该用例不被处理。
输出描述:
    对每个测试用例，在1行里输出最小的公路总长度。
示例1
输入
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
输出
3
5
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
  int from, to, w;
} eds[N * N];
bool tmp(ed e1, ed e2)
{
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
      scanf("%d%d%d", &eds[i].from, &eds[i].to, &eds[i].w);
    }
    sort(eds, eds + en, tmp);
    for (int i = 0; i < en; i++)
    {
      if (find(eds[i].from) != find(eds[i].to))
      {
        uni(eds[i].from, eds[i].to);
        ans += eds[i].w;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
