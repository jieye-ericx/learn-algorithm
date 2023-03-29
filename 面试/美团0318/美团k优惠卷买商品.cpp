/**
 * 现在商店里有N个物品，每个物品有原价和折扣价。
小美想要购买商品。小美拥有X元，一共Y张折扣券。
小美需要最大化购买商品的数量，并在所购商品数量尽量多的前提下，尽量减少花费。
你的任务是帮助小美求出最优情况下的商品购买数量和花费的钱数。
输入描述
第一行三个整数，以空格分开，分别表示N,X,Y。
接下来N行，每行两个整数，以空格分开，表示一个的原价和折扣价。
1≤N≤100, 1≤X≤5000, 1≤Y≤50，每个商品原价和折扣价均介于[1,50]之间。
输出描述
一行，两个整数，以空格分开。第一个数字表示最多买几个商品，第二个数字表示在满足商品尽量多的前提下所花费的最少的钱数。
样例输入
3 5 1
4 3
3 1
6 5
样例输出
2 5
提示
样例解释1
第一个商品原价购入，第二个商品折扣价购入，可以获得最多的商品数量2个。
此时消耗5元。因此输出 2 5。
输入样例2
3 5 1
4 3
3 1
6 1
输出样例2
2 4
样例解释2
可以发现有很多种买两个商品的方法。
最省钱的方案是第二个商品原价购入，第三个商品折扣价购入。此时花费4元。
输入样例3
10 30 3
2 1
3 2
2 1
10 8
6 5
4 3
2 1
10 9
5 4
4 2
输出样例3
8 24
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
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.second != p2.second)
    return p1.second < p2.second;
  return p1.first < p2.first;
}
int n, x, y;
int main()
{
  while (cin >> n >> x >> y)
  {
    int a, b, ans0 = 0, ans1 = 0, tmp_num = 0, tmp_cost = 0;
    vector<pair<int, int>> goods;
    for (int i = 0; i < n; i++)
    {
      cin >> a >> b;
      goods.emplace_back(a, b);
    }
    sort(goods.begin(), goods.end(), cmp);
    for (int i = 0; i < n; i++)
    {
      cout << goods[i].first << " " << goods[i].second << endl;
    }
    for (int i = 0; i < n; i++)
    {
      if (tmp_cost + goods[i].second <= x && y > 0)
      {
        y--;
        tmp_num++;
        tmp_cost += goods[i].second;
      }
      else if (tmp_cost + goods[i].first <= x)
      {
        tmp_num++;
        tmp_cost += goods[i].first;
      }
    }
    cout << tmp_num << " " << tmp_cost << endl;
  }

  return 0;
}
