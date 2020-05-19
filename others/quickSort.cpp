#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int quickSort(int left, int right);
void divide(int left, int right);
int a[] = {4, 5, 7, 9, 2, 1, 3, 11, 16};
int main()
{
  quickSort(0, 8);
  for (int i = 0; i < 9; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}

int quickSort(int left, int right)
{
  if(left==right)
    return 0;
  int mid = (left + right) >> 1;
  cout << left << " " << right << endl;
  divide(left, mid);
  divide(mid, right);
  quickSort(left, mid);
  quickSort(mid, right);
  return 0;
}

void divide(int left, int right)
{
  int divVal = a[left];
  int i = left, j = right;
  while (i < j)
  {
    while (a[j] >= divVal)
    {
      j--;
    }
    while (a[i] <= divVal)
    {
      i++;
    }
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }
  a[i] = divVal;
}