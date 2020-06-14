#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int solution(int n);
int main()
{
    cout << solution(362880) << endl;
    return 0;
}
int solution(int n)
{
    // write code here
    int digits = 1, tmp = 9;
    while (tmp < n)
    {
        tmp *= 9;
        digits *= 10;
    }
    cout << digits << endl;
    for (int i = digits; i < digits * 1000; i++)
    {
        int j = i, val = 1;
        while (j > 0)
        {
            val *= (j % 10);
            j /= 10;
        }
        if (val == n)
        {
            return i;
        }
    }
    cout << "213213";
    cout << "213213";
    cout << "213213";
    cout << "213213";
    cout << "213213";
    return -1;
}
