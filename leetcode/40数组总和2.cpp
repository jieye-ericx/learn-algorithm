/**
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
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
#include <set>
#include <list>
using namespace std;

int main()
{

  return 0;
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  int n = candidates.size();
  sort(candidates.begin(), candidates.end());

  vector<int> vis(n, 0), tmp;
  set<vector<int>> ans;
  vector<vector<int>> fans;
  dfs(0, candidates, target, ans, tmp, vis);
  for (auto it : ans)
  {
    fans.push_back(it);
  }
  return fans;
}
void dfs(int cur, vector<int> can, int target, set<vector<int>> &ans, vector<int> &tmp, vector<int> &vis)
{
  int n = can.size();
  if (cur > target)
    return;
  else if (cur == target)
  {
    sort(tmp.begin(), tmp.end());
    ans.insert(tmp);
  }
  for (int i = 0; i < n; i++)
  {
    if (vis[i] || cur + can[i] > target)
      continue;
    vis[i] = 1;
    tmp.push_back(can[i]);
    dfs(cur + can[i], can, target, ans, tmp, vis);
    tmp.pop_back();
    vis[i] = 0;
  }
}
