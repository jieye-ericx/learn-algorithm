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
const int N = 10004;
int father[N], height[N];
int rudu[N], vis[N]; //由于本题输入不是每个点都出现，所以需要这个数组来告诉我们这个点是否被输入
void init()
{
  for (int i = 0; i < N; i++)
  {
    father[i] = i;
    height[i] = 0;
  }
  memset(rudu, 0, sizeof(rudu));
  memset(vis, 0, sizeof(vis));
}
int fi(int x)
{
  if (x != father[x])
  {
    father[x] = fi(father[x]);
  }
  return father[x];
}
void uni(int x, int y)
{
  int fx = fi(x), fy = fi(y);
  if (fx != fy)
  {
    if (height[fx] < height[fy])
    {
      father[fx] = fy;
    }
    else if (height[fx] > height[fy])
    {
      father[fy] = fx;
    }
    else
    {
      father[fy] = fx;
      height[fx]++;
    }
  }
}
bool isOk()
{
  int root = 0, co = 0;
  for (int i = 0; i < N; i++)
  {
    if (!vis[i])
      continue;
    if (i == fi(i))
    {
      root++;
      if (root > 1)
        return false;
    }
    if (rudu[i] > 1)
      return false;
    else if (redu[i] == 0)
    {
      co++;
    }
  }
  if (co == 0 && root == 0)
    return true;
  if (co != 1 || root != 1)
    return false;
  return true;
}
int main()
{
  int x, y, cnt = 1;
  init();

  while (scanf("%d%d", &x, &y) != EOF && x != -1)
  {
    if (x == 0 && y == 0)
    {
      if (isOk())
      {
        printf("Case %d is a tree.\n", cnt++);
      }
      else
      {
        printf("Case %d is not a tree.\n", cnt++);
      }
      init();
    }
    else
    {
      uni(x, y);
      rudu[y]++;
      vis[x] = 1;
      vis[y] = 1;
    }
  }

  return 0;
}
