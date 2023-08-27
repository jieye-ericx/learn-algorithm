/**
 * 小美现在有一串彩带，假定每一厘米的彩带上都是一种色彩。

因为任务的需要，小美希望从彩带上截取一段，使得彩带中的颜色数量不超过K种。

显然，这样的截取方法可能非常多。于是小美决定尽量长地截取一段。

你的任务是帮助小美截取尽量长的一段，使得这段彩带上不同的色彩数量不超过K种。



输入描述
第一行两个整数N,K，以空格分开，分别表示彩带有N厘米长，你截取的一段连续的彩带不能超过K种颜色。

接下来一行N个整数，每个整数表示一种色彩，相同的整数表示相同的色彩。

1≤N,K≤5000，彩带上的颜色数字介于[1, 2000]之间。

输出描述
一行，一个整数，表示选取的彩带的最大长度。


样例输入
8 3
1 2 3 2 1 4 5 1
样例输出
5

提示
样例解释1

最长的一段彩带是[1, 2, 3, 2, 1]，共5厘米。
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

int n, k;
int main()
{
  int ans = 0, le = 0, ri = 0;
  unordered_map<int, int> tmpColor;
  cin >> n >> k;
  int color[n];
  for (int i = 0; i < n; i++)
  {
    cin >> color[i];
  }
  while (ri < n)
  {
    tmpColor[color[ri]]++;
    while (tmpColor.size() > k)
    {
      tmpColor[color[le]]--;
      if (tmpColor[color[le]] == 0)
      {
        tmpColor.erase(color[le]);
      }
      le++;
    }
    ans = max(ans, ri - le + 1);
    ri++;
  }
  cout << ans << endl;

  return 0;
}
