#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int quickSort(int a[],int left, int right);
int divide(int a[],int left, int right);
int main()
{
    int a[] = {4, 2, 23, 13, 55, 77, 345, 5, 7, 9, 2, 1, 3, 11, 16,99};
    quickSort(a,0, 15);
    for (int i = 0; i < 26; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

int quickSort(int a[] ,int left, int right)
{
    if (left < right)
    {
        int mid = divide(a,left, right);
        quickSort(a, left, mid - 1);
        quickSort(a, mid + 1, right);
    }
    return 0;
}

int divide(int a[] ,int left, int right)
{
    int divVal = a[left];
    while (left < right)
    {
        while (left < right && a[right] >= divVal)
        {
            right--;
        }
        a[left] = a[right];
        while (left < right && a[left] <= divVal)
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = divVal;
    return left;
}