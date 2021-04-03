/*
题目描述
输入年、月、日，计算该天是本年的第几天。
输入描述:
包括三个整数年(1<=Y<=3000)、月(1<=M<=12)、日(1<=D<=31)。
输出描述:
输入可能有多组测试数据，对于每一组测试数据，
输出一个整数，代表Input中的年、月、日对应本年的第几天。
示例1
输入
1990 9 20
2000 5 1
输出
263
122
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
int a[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
bool isR(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
int y, m, d, rflag, ds;
int main()
{
    while (cin >> y >> m >> d)
    {
        ds = 0;
        rflag = isR(y) == true ? 1 : 0;
        for (int i = 0; i < m - 1; i++)
        {
            ds += a[rflag][i];
        }
        ds += d;
        cout << ds << "\n";
    }

    return 0;
}
