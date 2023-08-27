// 米小游拿到了一个矩阵，矩阵上每一格有一个颜色，为红色(R)、绿色
// （G)和蓝色(B)这三种颜色的一种。
// 然而米小游是蓝绿色盲，她无法分辨蓝色和绿色，所以在米小游眼里看
// 来，这个矩阵只有两种颜色，因为蓝色和绿色在她眼里是一种颜色。
// 米小游会把相同颜色的部分看成是一个连通块。请注意，这里的连通块
// 是上下左右四连通的。由于色育的原因，米小游知道自己看到的连通块
// 数量可能比真实的连通块数量少。你可以帮米小游计算连通块少了多少
// 吗？

#include <iostream>
#include <vector>
using namespace std;

char c;
int n, m;
vector<vector<int>> a(1001, vector<int>(1001, 0));
vector<vector<int>> vis;

void dfs(int i, int j, int color)
{
  if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || a[i][j] != color)
  {
    return;
  }
  vis[i][j] = 1;
  dfs(i - 1, j, color);
  dfs(i + 1, j, color);
  dfs(i, j - 1, color);
  dfs(i, j + 1, color);
}
int comp()
{
  vis.assign(n, vector<int>(m, 0));
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vis[i][j] == 0)
      {
        dfs(i, j, a[i][j]);
        ans++;
      }
    }
  }
  return ans;
}
int main()
{
  while (cin >> n >> m)
  {

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> c;
        if (c == 'R')
          a[i][j] = 0;
        else if (c == 'G')
          a[i][j] = 1;
        else
          a[i][j] = 2;
      }
    }
    int a1 = comp();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (a[i][j] == 1)
        {
          a[i][j] = 2;
        }
      }
    }
    int a2 = comp();
    cout << a1 - a2 << endl;
  }

  return 0;
}