#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
/* 题目描述
设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，
且有：abc+bcc=532。求满足条件的所有a、b、c的值。
输入描述:
题目没有任何输入。
输出描述:
请输出所有满足题目条件的a、b、c的值。
a、b、c之间用空格隔开。
每个输出占一行。 */
int main()
{
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 1; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (100 * (b + a) + 10 * (b + c) + 2 * c == 532)
                    printf("%d %d %d\n", a, b, c);
            }
        }
    }
    return 0;
}
