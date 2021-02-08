/*
给你n个整数，请按从大到小的顺序输出其中前m大的数。
Input
每组测试数据有两行，第一行有两个数n,m(0<n,m<1000000)，第二行包含n个各不相同，且都处于区间[-500000,500000]的整数。
Output
对每组测试数据按从大到小的顺序输出前m大的数。
Sample Input
5 3
3 -35 92 213 -644
Sample Output
213 92 3
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int n, m, t, a[1000003];
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &t);
            a[t + 500000]++;
        }
        int cnt = 0;
        for (int i = 1000000; i > 0; i--)
        {
            if (a[i] != 0)
            {
                cnt++;
                printf("%d", i - 500000);
                if (cnt < m)
                    printf(" ");
                else
                {
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}
