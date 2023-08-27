#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int T, N;
vector<int> a, ans1, ans2;
set<int> se;
int main()
{
  while (cin >> N)
  {
    a = vector<int>(N);
    ans1 = vector<int>(N);
    ans2 = vector<int>(N);
    se.clear();
    int leiji = 0;
    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
      leiji += a[i];
      ans1[i] = round(double(leiji) / double(i + 1));
      se.insert(a[i]);
      int cnt = 0, n = se.size(), cntt, tmp1, tmp2, cnttt;
      cntt = (n - 1) / 2;
      cnttt = cntt + 1;
      for (auto x : se)
      {
        if (cnt > cnttt)
        {
          break;
        }
        else if (cnt == cntt)
        {
          tmp1 = x;
        }
        else if (cnt == cnttt)
        {
          tmp2 = x;
        }
        cnt++;
      }
      if (n & 1)
      {
        ans2[i] = tmp1;
      }
      else
      {
        ans2[i] = round(double((tmp1) + double(tmp2)) / 2);
      }
    }
    cout << ans1[0];
    for (int i = 1; i < N; i++)
    {
      cout << " " << ans1[i];
    }
    cout << endl;
    cout << ans2[0];
    for (int i = 1; i < N; i++)
    {
      cout << " " << ans2[i];
    }
    cout << endl;
  }
}