#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int T, N;
// vector<vector<int>> a;
vector<int> a;
vector<string> ss;

int main()
{
  while (cin >> N)
  {
    int cnt = 0;
    while (N--)
    {
      cin >> ss[cnt++];
    }
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