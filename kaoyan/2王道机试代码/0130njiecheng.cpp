#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int n;
long long a[22];
int main()
{
    a[1] = 1;
    for (int i = 2; i < 21; i++)
    {
        a[i] = i * a[i - 1];
    }

    while (cin >> n)
    {
        cout << a[n] << "\n";
    }
    return 0;
}
