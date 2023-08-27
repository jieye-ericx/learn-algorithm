/***
 * 游游定义一个排列中，满足以下条件的为"好元素",对于第i个元素ai而言，ai为前i个元素的最大值。
 * 例如，[3,1,5,2,4]中，第一个和第三个元素是好元素。
游游希望你构造一个长度为n的排列，其中有k个好元素，且任意两个好元素都不相邻。
排列的定义：由1到几所有正整数组成的长度为机的数绝，每个正整發出城
次。
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
vector<int> constructPermutation(int n, int k)
{
  vector<int> res = vector<int>(n, 0);
  int st = n - k + 1, i = 1;
  for (int j = 0; j < n; j++)
  {
    res[j] = j & 1 ? i++ : st > n ? i++
                                  : st++;
  }
  return res;
}
int main()
{
  vector<int> a = constructPermutation(5, 3);
  for (auto &&v : a)
  {
    cout << v << " ";
  }

  return 0;
}
