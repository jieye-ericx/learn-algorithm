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

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMaximumSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER k
 */
void dfs(int m, int n, int num, vector<vector<int>> v, int ans, vector<vector<int>> matrix);
int Lans;
void dfs(int m, int n, int num, vector<vector<int>> v, int ans, vector<vector<int>> matrix)
{
  if (num == 0)
  {
    Lans = max(Lans, ans);
    return;
  }
  for (int i = 0; i < m; i++)
  {
    if (v[i][0] > v[i][1])
    {
      continue;
    }
    if (v[i][0] < n && v[i][0] <= v[i][1])
    {
      ans += matrix[i][v[i][0]];
      v[i][0]++;
      dfs(m, n, num - 1, v, ans, matrix);
      v[i][0]--;
      ans -= matrix[i][v[i][0]];
    }
    if (v[i][1] >= 0 && v[i][1] >= v[i][0])
    {
      ans += matrix[i][v[i][1]];
      v[i][1]--;
      dfs(m, n, num - 1, v, ans, matrix);
      v[i][1]++;
      ans -= matrix[i][v[i][1]];
    }
  }
};
int getMaximumSum(vector<vector<int>> matrix, int k)
{
  int m = matrix.size();
  if (m == 0)
  {
    return 0;
  }
  int n = matrix[0].size();
  int ans = -100;
  Lans = -1000;
  vector<vector<int>> v;
  for (int i = 0; i < m; i++)
  {
    v.push_back(vector<int>(2));
    v[i][0] = 0;
    v[i][1] = n - 1;
  }

  dfs(m, n, k, v, 0, matrix);
  return Lans;
}

int main()
{
  vector<vector<int>> ma;
  ma.push_back(vector<int>{6, 5, 8, 1});
  ma.push_back(vector<int>{7, 5, 10, 3});
  ma.push_back(vector<int>{5, 1, 9, 6});
  cout << getMaximumSum(ma, 4) << endl;
  ma.clear();
  ma.push_back(vector<int>{3, 7, 2});
  ma.push_back(vector<int>{4, 1, 5});
  cout << getMaximumSum(ma, 3);

  return 0;
}