#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int su[10004], m, n;
bool isP(int);
void getSu()
{
  su[1] = 2;
  su[2] = 3;
  su[3] = 5;
  su[4] = 7;
  int cnt = 5;
  bool flag = false;
  for (int a = 12;; a += 6)
  {
    if (isP(a - 1))
    {
      su[cnt++] = a - 1;
    }
    if (isP(a + 1))
    {
      su[cnt++] = a + 1;
    }
    if (cnt >= 10001)
    {
      break;
    }
  }
}

bool isP(int x)
{
  for (int i = 3; i < sqrt(x) + 1; i += 2)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}
int main()
{
  getSu();
  while (cin >> m >> n)
  {
    int cnt = 0;
    for (int i = m; i <= n; i++, cnt++)
    {
      if (cnt == 0)
      {
      }
      else if (cnt == 10)
      {
        cout << "\n";
        cnt = 0;
      }
      else
      {
        cout << " ";
      }

      cout << su[i];
    }
  }
  return 0;
}
