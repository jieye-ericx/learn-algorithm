#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
  int a[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5};
  int x = 4, k = 0;
  for (int i = 0; i < sizeof(a) / sizeof(int); i++)
  {
    if (a[i] == x)
    {
      k++;
    }
    else
    {
      a[i - k] = a[i];
    }
  }
  for (int i = 0; i < 15; i++)
  {
    cout << a[i] << " ";
  }
  cout << k;
  return 0;
}
