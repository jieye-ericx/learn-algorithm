/**
小美明天要去春游了。她非常喜欢吃巧克力，希望能够带尽可能多的巧克力在春游的路上吃。
她现在有n个巧克力，很巧的是她所有的巧克力都是厚度一样的正方形的巧克力板，这n个巧克力板的边长分别为a1,a2,...,an。因为都是厚度一致的正方形巧克力板，
我们认为第 i 个巧克力的重量为ai^2。小美现在准备挑选一个合适大小的包来装尽可能多的巧克力板，她十分需要你的帮助来在明天之前准备完成，请你帮帮她。
输入描述
第一行两个整数n和m，表示小美的巧克力数量和小美的询问数量。
第二行n个整数a1,a2,...,an，表示n块正方形巧克力板的边长。注意你不能将巧克力板进行拆分。
第三行m个整数q1,q2,...,qm，第 i 个整数qi表示询问：如果小美选择一个能装qi重量的包，最多能装多少块巧克力板？（不考虑体积影响，我们认为只要质量满足要求，巧克力板总能塞进包里）
1≤n,m≤50000,1≤ai≤10^4,1≤qi≤10^18
输出描述
输出一行m个整数，分别表示每次询问的答案。
 *
 */

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;
#define debug(a) cout << #a << "=" << a << endl;
#define lyh(i, a, b) for (int i = a; i <= b; i++)
#define hyl(i, a, b) for (int i = a; i >= b; i--)
#define LL long long
int n, m, t;
vector<LL> q, arr;
int comp(LL val)
{
  if (val < arr[0])
  {
    return 0;
  }
  auto aa = arr.begin();
  aa++;
  auto it = upper_bound(aa, arr.end(), val);
  if (it == arr.end())
    return arr.size() - 1;
  else

    return it - aa;
}
int main()
{
  while (cin >> n >> m)
  {
    arr = vector<LL>(n + 1, 0);
    q = vector<LL>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      cin >> t;
      arr[i] = arr[i - 1] + t * t;
    }
    for (int i = 0; i < m; i++)
    {
      cin >> q[i];
    }
    sort(arr.begin(), arr.end());
    if (m > 0)
      cout << comp(q[0]);
    for (int i = 1; i < m; i++)
    {
      cout << " " << comp(q[i]);
    }
    cout << "\n";
  }

  return 0;
}
