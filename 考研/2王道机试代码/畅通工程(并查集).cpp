/* 题目描述
    某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
    省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，
    只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？
输入描述:
    测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
    注意:两个城市之间可以有多条道路相通,也就是说
    3 3
    1 2
    1 2
    2 1
    这种输入也是合法的
    当N为0时，输入结束，该用例不被处理。
输出描述:
    对每个测试用例，在1行里输出最少还需要建设的道路数目。
示例1
输入
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
输出
1
0
2
998 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <list>
using namespace std;
int n, m, st, ed, father[1002], hei[1002];
void init()
{
  for (int i = 0; i < 1002; i++)
  {
    father[i] = i;
    hei[i] = 0;
  }
}
int fa(int x)
{
  if (x != father[x])
  {
    father[x] = fa(father[x]);
  }
  return father[x];
}
void uni(int x, int y)
{
  x = fa(x);
  y = fa(y);
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
    scanf("%d", &m);
    init();
    for (int i = 1; i <= m; i++)
    {
      scanf("%d%d", &st, &ed);
      uni(st, ed);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
      if (fa(i) == i)
      {
        ans++;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
