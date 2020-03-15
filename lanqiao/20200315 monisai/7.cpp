#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;
int ans = 0, n;
bool work(int x)
{
    int pre = x % 10;
    while (x)
    {
        int t = x % 10;
        if (pre >= t)
        {
            t = pre;
        }
        else
            return false;
        x /= 10;
    }
    return true;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (work(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
/*
问题描述
　　一个正整数如果任何一个数位不大于右边相邻的数位，则称为一个数位递增的数，例如1135是一个数位递增的数，而1024不是一个数位递增的数。
　　给定正整数 n，请问在整数 1 至 n 中有多少个数位递增的数？
输入格式
　　输入的第一行包含一个整数 n。
输出格式
　　输出一行包含一个整数，表示答案。
样例输入
30
样例输出
26
评测用例规模与约定
　　对于 40% 的评测用例，1 <= n <= 1000。
　　对于 80% 的评测用例，1 <= n <= 100000。
　　对于所有评测用例，1 <= n <= 1000000。
*/