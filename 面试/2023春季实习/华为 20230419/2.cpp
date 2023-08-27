/*
给定一棵树，这个树有n个节点，节点编号从0开始依次递增，0固定为根节点。在这棵树上有一个小猴子，初始时该猴子位于根节点 （0号） 上，小猴子一次可以沿着树上的边从一个节点挪到另一个节点，但这棵树上有一些节点设置有障碍物，如果某个节点上设置了障碍物，小猴子就不能通过连接该节点的边挪动到该节点上。问小猴子是否能跑到树的叶子节点（叶子节点定义为只有一条边连接的节点），如果可以，请输出小猴子跑到叶子节点的最短路径（通过的边最少），否则输出字符串NULL。
输入
第一行给出数字n，表示这个树有n个节点，节点编号从0开始依次递增，0固定为根节点，1<=n<10000
第二行给出数宇edge，表示接下来有edge行，每行是一条边
接下来的edge行是边：x y，表示x和y节点有一条边连接
边信息结束后接下来的一行给出数宇block，表示接下来有block行，每行是一个障碍物
接下来的block行是障碍物：x，表示节点x上存在障碍物
输出
如果小猴子能跑到树的叶子节点，请输出小猴子跑到叶子节点的最短路径（通过的边最少，比如小猴子从0经过1到达2 （叶子节点），那么输出“0->1->2”；否则输出"NULL”。注意如果存在多条最短路径，请按照节点序号排序输出，比如0->1和0->3两条路径，第一个节点0一样，则比较第二个节点1和3，1比3小，因此输出0->1这条路径。再如 0->5->2->3和 0->5->1->4，则输出 0->5->1->4。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAXN = 10000;
vector<int> adj[MAXN];
bool blocked[MAXN];
int dist[MAXN];
int parent[MAXN];

string shortestPath(int n)
{
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  parent[0] = -1;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (int v : adj[u])
    {
      if (!blocked[v] && v != parent[u])
      {
        dist[v] = dist[u] + 1;
        parent[v] = u;
        q.push(v);
      }
    }
  }

  int leaf = -1;
  for (int i = 0; i < n; i++)
  {
    if (adj[i].size() == 1 && !blocked[i] && (leaf == -1 || dist[i] < dist[leaf]))
    {
      leaf = i;
      break;
    }
  }
  if (leaf == -1 || (leaf == 0 && n > 1))
  {
    return "NULL";
  }

  vector<int> path;
  while (leaf != -1)
  {
    path.emplace_back(leaf);
    leaf = parent[leaf];
  }
  reverse(path.begin(), path.end());
  string result = "";
  for (int i = 0; i < path.size(); i++)
  {
    result += to_string(path[i]);
    if (i < path.size() - 1)
    {
      result += "->";
    }
  }
  return result;
}

int main()
{
  int n, m;
  cin >> n >> m;
  memset(blocked, 0, sizeof(blocked));
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int b;
  cin >> b;
  for (int i = 0; i < b; i++)
  {
    int x;
    cin >> x;
    blocked[x] = true;
  }
  cout << shortestPath(n) << endl;
  return 0;
}