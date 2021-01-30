#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
string a, b;
int sum;
int main()
{
    while (cin >> a >> b)
    {
        sum = 0;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                int x = a[i] - 48, y = b[j] - 48;
                // cout << x << " " << y << endl;
                sum += x * y;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
