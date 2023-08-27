#include <iostream>
#include <vector>
using namespace std;

const int N = 100001;

vector<pair<int, int>> adj[N];
bool visited[N], red[N];
int max_weight = 0;

void dfs(int u, int parent_edge_weight)
{
  max_weight = max(max_weight, parent_edge_weight);
  for (auto edge : adj[u])
  {
    int v = edge.first, w = edge.second;
    if (!visited[v])
    {
      visited[v] = true;
      if (!red[v] && !red[u])
      {
        red[v] = true;
        red[u] = true;
        dfs(v, parent_edge_weight + w);
        red[v] = false;
        red[u] = false;
      }
      else
      {
        dfs(v, parent_edge_weight);
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  visited[1] = true;
  dfs(1, 0); // 从根节点开始搜索
  cout << max_weight << endl;
  return 0;
}