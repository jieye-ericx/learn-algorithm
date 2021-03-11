/* 题目描述
名名的妈妈从外地出差回来，带了一盒好吃又精美的巧克力给名名（盒内共有 N 块巧克力，20 > N >0）。 
妈妈告诉名名每天可以吃一块或者两块巧克力。 
假设名名每天都吃巧克力，问名名共有多少种不同的吃完巧克力的方案。 
例如： 如果N=1，则名名第1天就吃掉它，共有1种方案； 
如果N=2，则名名可以第1天吃1块，第2天吃1块，也可以第1天吃2块，共有2种方案； 
如果N=3，则名名第1天可以吃1块，剩2块，也可以第1天吃2块剩1块，所以名名共有2+1=3种方案； 
如果N=4，则名名可以第1天吃1块，剩3块，也可以第1天吃2块，剩2块，共有3+2=5种方案。 
现在给定N，请你写程序求出名名吃巧克力的方案数目。
输入描述:
输入只有1行，即整数N。
输出描述:
可能有多组测试数据，对于每组数据，
输出只有1行，即名名吃巧克力的方案数。
示例1
输入
复制
4
输出
复制
5 */
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
int n, dp[200];
int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= 200; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", dp[n]);
    }

    return 0;
}
