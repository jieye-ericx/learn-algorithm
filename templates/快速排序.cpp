#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
// 注意两点，17，20行的i<j不能丢
// 30行的边界判断
// 快速排序
int n, a[102];
int divd(int le, int ri)
{
    int t = a[le], i = le, j = ri;
    while (i < j)
    {
        while (a[j] >= t && i < j)
            j--;
        a[i] = a[j];
        while (a[i] <= t && i < j)
            i++;
        a[j] = a[i];
    }
    a[j] = t;
    return j;
}
void quic(int leftv, int rightv)
{
    if (leftv >= rightv)
        return;
    int mid = divd(leftv, rightv);
    quic(leftv, mid - 1);
    quic(mid + 1, rightv);
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        quic(0, n - 1);
        printf("%d", a[0]);
        for (int i = 1; i < n; i++)
        {
            printf(" %d", a[i]);
        }
        // printf("/n");
    }

    return 0;
}
