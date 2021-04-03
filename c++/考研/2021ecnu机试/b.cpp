/* 
Cuber QQ 决定搞一个新的爱好，他发现一个牌类游戏叫做桥。

四个玩家，有  张牌，有  个不同的值（ A, K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3 和 2 ）。在游戏的开始，每个人都有  张牌。

在游戏开始前，规定荣誉分如下：

每张  得  分。

每张  得  分。

每张 得  分。

每张  得  分。

其余牌用  表示，得  分。

Cuber QQ 想要练习计分数，他洗了  次牌，想要把他的荣誉分加起来。

请帮助 Cuber QQ 完成这个任务。

输入格式
第一行一个整数 （）
接下来 行，每行为长度  的字符串，包含 AKQJX 字符。

输出格式
一行一个整数，表示答案，荣誉分之和。

样例
input
1
AKXAKJXXXAXAQ
output
25

 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int ax, ay, bx, by, n, m, arr[201][201], vis[201][201], ans[201][201], ans1[201][201];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, las;
char c;
void dfs(int x, int y, int dep, int turn);
int main()
{
  while (scanf("%d%d", &n, &m) != EOF)
  {
    memset(arr, 0, sizeof(arr));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    memset(ans1, 0, sizeof(ans1));
    las = 0xffffff;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> c;
        if (c == '.')
          arr[i][j] = 3;
        else if (c == '#')
          arr[i][j] = 4;
        else if (c == '*')
          arr[i][j] = 5;
        else if (c == 'A')
        {
          ax = i, ay = j;
          arr[i][j] = 3;
        }
        else if (c == 'B')
        {
          bx = i, by = j;
          arr[i][j] = 3;
        }
      }
    }
    dfs(ax, ay, 0, 0);
    memset(vis, 0, sizeof(vis));
    dfs(bx, by, 0, 1);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (ans[i][j] == 0)
          continue;
        las = min(las, ans1[i][j] + ans[i][j]);
      }
    }
    printf("%d\n", las);
  }

  return 0;
}
/* 
5 5
A..*.
.#...
.#...
*..B.
#...#

 */
void dfs(int x, int y, int dep, int turn)
{
  if (turn == 0)
  {
    if (arr[x][y] == 5)
    {
      if (ans[x][y] != 0)
      {
        ans[x][y] = min(ans[x][y], dep);
      }
      else
        ans[x][y] += dep;
      return;
    }
  }
  else
  {
    if (arr[x][y] == 5)
    {
      if (ans1[x][y] != 0)
      {
        ans1[x][y] = min(ans1[x][y], dep);
      }
      else
        ans1[x][y] += dep;
      return;
    }
  }

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];
    if (x < 0 || y < 0 || x >= n || y >= m)
    {
      continue;
    }
    if (vis[nx][ny] || arr[nx][ny] == 4)
      continue;
    vis[nx][ny] = 1;
    dfs(nx, ny, dep + 1, turn);
    vis[nx][ny] = 0;
  }
}