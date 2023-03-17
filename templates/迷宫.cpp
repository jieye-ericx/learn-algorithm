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
typedef pair<int, int> PII;
const int N = 1005;
int n, mp[N][N], dix[4] = {0, 0, 1, -1}, diy[4] = {1, -1, 0, 0};
bool st[N][N];
PII path[N][N];
void bfs(int x, int y)
{
  queue<PII> q;
  q.push({x, y});
  st[x][y] = true;
  while (!q.empty())
  {
    auto res = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int xx = dix[i] + res.first, yy = diy[i] + res.second;
      if (xx < 0 || xx >= n || yy < 0 || yy >= n || mp[xx][yy])
        continue;
      if (st[xx][yy])
        continue;
      path[xx][yy] = {res.first, res.second};
      q.push({xx, yy});
      st[xx][yy] = true;
      if (xx == 0 && yy == 0)
        return;
    }
  }
}
int main()
{
  memset(path, -1, sizeof path);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> mp[i][j];
  bfs(n - 1, n - 1);
  int u = 0, v = 0;
  while (u >= 0 && v >= 0)
  {
    cout << u << " " << v << endl;
    auto res = path[u][v];
    u = res.first, v = res.second;
  }
}