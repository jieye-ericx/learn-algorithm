#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

int intTochar(int n, int sum)
{
    // cout << sum << endl;
    if (n == 1)
    {
        return sum;
    }
    if (n % 5 == 0)
    {
        return intTochar(n - 1, sum + 1);
    }
    else
    {
        return intTochar(n - 1, sum);
    }
}

int main()
{
    int num = 49;
    cout << "111111111" << intTochar(num, 0);
    // cout << "111111111" << intTochar(num, 0);
    return 0;
}