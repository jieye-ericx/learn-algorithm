#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
vector<int> countBits(int num);
int main()
{
    countBits(2);
    //! 朴素解法，0<=i<=num每个进行遍历 cout << __builtin_popcount(a);
    return 0;
}
//!dp
vector<int> countBits(int num)
{
    vector<int> dp(num + 1, 0);
    int base = 1;
    dp[0] = 0;

    for (int i = 1; i <= num; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            cout << i << endl;
            base = i;
            dp[i] = 1;
        }
        else
        {
            dp[i] = dp[i - base] + 1;
        }
    }
    return dp;
}
