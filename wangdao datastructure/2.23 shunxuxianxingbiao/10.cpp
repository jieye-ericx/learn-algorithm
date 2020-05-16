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
  int a[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5}, k = 0;
  for (int i = 0; i <= sizeof(a) / sizeof(int) - 1; i++)
  {
    cout<< a[(i + 4) % 15]<<" ";
  }
  // for (int i = 0; i < 15; i++)
  // {
  //   cout << a[i] << " ";
  // }
  return 0;
}
