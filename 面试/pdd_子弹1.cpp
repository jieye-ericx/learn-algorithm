#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int T, N;
// vector<vector<int>> a;
vector<int> a;

int main()
{
  while (cin >> T >> N)
  { // 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    a = vector<int>(N);
    int Lans, cur;
    while (T--)
    {
      cur = 0;
      Lans = 0;
      a.clear();
      for (int j = 0; j < N; j++)
      {
        cin >> a[j];
      }
      sort(a.begin(), a.end());
      for (int j = 0; j < N; j++)
      {
        if (a[j] >= 2)
        {
          Lans++;
        }
        else if (cur >= a[j])
        {
          cur -= a[j];
        }
        else
        {
          cur++;
          Lans++;
        }
      }
      cout << Lans << endl;
    }
  }
}