/* https://www.nowcoder.com/practice/41b14b4cd0e5448fb071743e504063cf?tpId=61&tqId=29512&tPage=1&rp=1&ru=%2Fta%2Fpku-kaoyan&tab=answerKey
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
// ----------
struct point
{
  double x, y;
} ps[N];
struct ed
{
  int from, to;
  double w;
} eds[N * N];
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
    int en = n, cnt = 0;
    for (int i = 0; i < en; i++)
    {
      scanf("%lf%lf", &ps[i].x, &ps[i].y);
      // for (int j = 0; j < i; j++)
      // {
      //   eds[cnt].from = j + 1;
      //   eds[cnt].to = i + 1;
      //   //!如果在这里对w进行赋值，那么只会记录当前结点和已经输入结点的距离，后面的结点就被略过了！
      // eds[cnt++].w = sqrt(pow((x - ps[j].x), 2) + pow((y - ps[j].y), 2));
      // eds[cnt++].w = sqrt(pow((x - ps[j].x), 2) + pow((y - ps[j].y), 2));
      // }
    }
    for (int i = 0; i < en; i++)
    {
      for (int j = i + 1; j < en; j++)
      {
        eds[cnt].from = i + 1;
        eds[cnt].to = j + 1;
        eds[cnt++].w = sqrt(pow((ps[i].x - ps[j].x), 2) + pow((ps[i].y - ps[j].y), 2));
      }
    }

    sort(eds, eds + cnt);
    // for (int i = 0; i < cnt; i++)
    // {
    //   cout << eds[i].from << " " << eds[i].to << " " << eds[i].w << endl;
    // }
    double ans = 0.0;
    for (int i = 0; i < cnt; i++)
    {
      if (find(eds[i].from) != find(eds[i].to))
      {
        uni(eds[i].from, eds[i].to);
        ans += eds[i].w;
      }
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
