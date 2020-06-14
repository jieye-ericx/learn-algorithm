#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;
const int N = 1010;
int n, ans = 0;
int f[N][N]; 

int dfs(int pre, int now)
{
    if (f[pre][now] != -1)
        return f[pre][now];
    int t = 1;
    for (int i = 1; i < abs(pre - now); i++)
    {
        t = (t+dfs(now, i))%10000;
    }
    return f[pre][now] = t % 10000;
}
int main()
{
    fill(f[0], f[0] + N * N, -1);
    cin >> n;
    f[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dfs(n, i)) % 10000;
    }
    cout << ans << endl;
    return 0;
}
/*
小明想知道，满足以下条件的正整数序列的数量：
　　1. 第一项为 n；
　　2. 第二项不超过 n；
　　3. 从第三项开始，每一项小于前两项的差的绝对值。
　　请计算，对于给定的 n，有多少种满足条件的序列。
输入格式
　　输入一行包含一个整数 n。
输出格式
　　输出一个整数，表示答案。答案可能很大，请输出答案除以10000的余数。
样例输入
4
样例输出
7
样例说明
　　以下是满足条件的序列：
　　4 1
　　4 1 1
　　4 1 2
　　4 2
　　4 2 1
　　4 3
　　4 4
评测用例规模与约定
　　对于 20% 的评测用例，1 <= n <= 5；
　　对于 50% 的评测用例，1 <= n <= 10；
　　对于 80% 的评测用例，1 <= n <= 100；
　　对于所有评测用例，1 <= n <= 1000。
*/