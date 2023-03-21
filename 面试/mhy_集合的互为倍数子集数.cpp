#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;
int main()
{
  while (cin >> n)
  {
    a = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int ans = 0;
    vector<vector<int>> dp(1 << n, vector<int>(10001));
    for (int i = 0; i < n; i++)
    {
      dp[1 << i][a[i]] == 1;
    }

    for (int m = 0; m < (1 << n); m++)
    {
      for (int i = 0; i < 10001; i++)
      {
        dp[m][i] = (dp[m][i] + dp[m][i - 1]) % 1000000007;
      }
      for (int i = 0; i < n; i++)
      {
        if (!(m & (1 << i)))
        {
          int next = a[i];
          if (next <= 10001)
          {
            dp[m | (1 << i)][next] = (dp[m | (1 << i)][next] + dp[m][next / a[i]]) % 1000000007;
          }
        }
      }
    }
    int tmp;
    for (int i = 0; i < (1 << n); i++)
    {
      tmp = (dp[m][10001] - dp[m][1] + 1000000007) % 1000000007;
      if (tmp > 1)
      {
        ans = (ans + tmp) % 1000000007;
      }
    }
    cout << ans << endl;
    // for (int i = 0; i < n; i++)
    // {
    //   cout << a[i];
    // }
  }

  return 0;
}