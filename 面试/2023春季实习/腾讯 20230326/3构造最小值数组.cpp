// http://101.43.147.120/p/P1124
#include <bits/stdc++.h>
using namespace std;

vector<int> v[3]; // 按b数组0、1、2分组
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int &t : a)
    cin >> t;
  for (int i = 0; i < n; i++)
  {
    cin >> b[i]; // 此处的值对应b数组
    v[b[i]].push_back(a[i]);
  }
  int x = 0; // c数组的值
  long long ans = 0;
  for (int i = 0; i < 3; i++)
  {
    sort(v[i].begin(), v[i].end()); // 组内排序，和c数组从1开始匹配
    for (int t : v[i])
    {
      x++;
      ans += abs(t - x); // 记录答案
    }
  }
  cout << ans << endl;
}
