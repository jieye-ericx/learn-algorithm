// https://www.nowcoder.com/practice/7c29cdfa28274c86afc9e88c07448a10?tpId=62&tqId=31040&tPage=2&ru=%2Fkaoyan%2Fretest%2F2002&qru=%2Fta%2Fsju-kaoyan%2Fquestion-ranking&tab=answerKey
/* 
题目描述
该题的目的是要你统计图的连通分支数。
输入描述:
每个输入文件包含若干行，每行两个整数i,j，表示节点i和j之间存在一条边。
输出描述:
输出每个图的联通分支数。
示例1
输入
1 4
4 3
5 5
输出
2 */
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
// !对于这种输入不是连续的结点，可以使用map
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> father; //通过散列表map实现的father数组
map<int, int> height; //记录每个节点的高度
int find(int x)
{
  if (father.find(x) != father.end())
  {
    if (father[x] != x)
      father[x] = find(father[x]); //路径压缩(最后自己通过例子模拟下过程)
  }
  else
  { //如果还没有出现的新节点。把father设成他自己(表示根节点)，height设成0
    father[x] = x;
    height[x] = 0;
  }
  return father[x];
}
void Union(int a, int b)
{ //合并函数
  a = find(a);
  b = find(b);
  if (a != b)
  {
    if (height[a] > height[b])
      father[b] = a;
    else if (height[b] > height[a])
      father[a] = b;
    else
    {
      father[a] = b;
      height[a]++;
    }
  }
}
int main()
{
  int i, j;
  while (cin >> i >> j)
  {
    //if(i==0)break;
    Union(i, j);
  }
  int sum = 0;
  for (auto it = father.begin(); it != father.end(); it++)
  {
    if (it->first == it->second)
      sum++; //只要有一个父亲是本身的就说明是根节点
  }
  cout << sum << endl;
  return 0;
}
// !以下是我的代码
const int N = 1000004;
int x, y, vis[N], maxNum = 0, ans = 0;
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
  x = find(x), y = find(y);
  if (x != y)
  {
    if (hei[x] > hei[y])
    {
      father[y] = x;
    }
    else if (hei[x] < hei[y])
    {
      father[x] = y;
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
  init();
  memset(vis, 0, sizeof(vis));
  while (scanf("%d%d", &x, &y) != EOF)
  {
    maxNum = max(maxNum, max(x, y));
    vis[x] = 1, vis[y] = 1;
    uni(x, y);
  }
  for (int i = 0; i <= maxNum; i++)
  {
    if (vis[i])
    {
      if (i == father[i])
        ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
