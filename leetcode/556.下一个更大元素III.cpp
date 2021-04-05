/* 
给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。
如果不存在这样的正整数，则返回 -1 。
注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
示例 1：
输入：n = 12
输出：21
示例 2：
输入：n = 21
输出：-1
 */
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
int nextGreaterElement(int n);
int main()
{
    cout << nextGreaterElement(12);
    return 0;
}
int nextGreaterElement(int n)
{
    vector<int> a;
    stack<int> s;
    while (n > 0)
    {
        a.insert(a.begin(), n % 10);
        n /= 10;
    }
    for (int i = a.size() - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            for (int j = a.size() - 1; j > i; j--)
            {
                if (a[j] > a[i])
                {
                    // cout << "j= " << j << "i=" << i << endl;
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                    long ans = 0;
                    int base = 1;
                    for (int k = a.size() - 1; k >= 0; k--)
                    {
                        ans += (long)(a[k] * base);
                        base *= 10;
                    }
                    // cout << ans;
                    if (ans > (1 << 30))
                        return -1;
                    else
                        return (int)ans;
                }
            }
        }
    }
    return -1;
}