#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x)
{
  if (Tree[x] == -1)
    return x;
  else
    return findRoot(Tree[x]);
}
struct Edge
{
  int a, b, cost;
  bool operator<(const Edge &A) const
  {
    return cost < A.cost;
  }
} list[6000];
int main()
{
  int n;
  while (scanf("%d", &n) != EOF && n != 0)
  {
    for (int i = 1; i <= n; i++)
      Tree[i] = -1;
    int c = n * (n - 1) / 2;
    for (i = 0; i < c; i++)
    {
      scanf("%d%d%d", &list[i].a, &list[i].b, &list[i].cost);
    }
    sort(list, list + c);
    int ans = 0;
    for (i = 0; i < c; i++)
    {
      int a = findRoot(list[i].a);
      int b = findRoot(list[i].b);
      if (a != b)
      {
        Tree[a] = b;
        ans += list[i].cost;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}