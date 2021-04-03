/*Input
输入只有1行，一个正整数 X 2 ≤ X ≤ 105
Output
输出一行，一个整数，为不小于X的最小质数.
Sample 1
20
23
不小于20的最小质数是 23.
Sample 2
2
2
X 本身可能是质数，就输出X.
Sample 3
99992
100003
*/
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
bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
};
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = n;; i++)
        {
            if (isPrime(i))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
