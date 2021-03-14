/* 题目描述
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学不交换位置就能排成合唱队形。 
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1, 2, …, K，他们的身高分别为T1, T2, …, TK， 
则他们的身高满足T1 < T2 < … < Ti , Ti > Ti+1 > … > TK (1 <= i <= K)。 
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
输入描述:
输入的第一行是一个整数N（2 <= N <= 100），表示同学的总数。
第一行有n个整数，用空格分隔，第i个整数Ti（130 <= Ti <= 230）是第i位同学的身高（厘米）。
输出描述:
可能包括多组测试数据，对于每组数据，
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。
示例1
输入
复制
8
186 186 150 200 160 130 197 220
输出
复制
4 */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int arr[1004], n;
vector<int> cal1(int a[], int n);
vector<int> cal2(int a[], int n);
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        vector<int> v1 = cal1(arr, n);
        vector<int> v2 = cal2(arr, n);
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            ans = min(n - (v1[i] + v2[i] - 1), ans);
        }
        printf("%d\n", ans);
    }

    return 0;
}
vector<int> cal1(int a[], int n)
{
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}
vector<int> cal2(int a[], int n)
{
    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}
