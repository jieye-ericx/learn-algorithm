/*
读入N名学生的成绩，将获得某一给定分数的学生人数输出。
输入描述:
测试输入包含若干测试用例，每个测试用例的格式为
第1行：N
第2行：N名学生的成绩，相邻两数字用一个空格间隔。
第3行：给定分数
当读到N=0时输入结束。其中N不超过1000，成绩分数为（包含）0到100之间的一个整数。
输出描述:
对每个测试用例，将获得给定分数的学生人数输出。
输入
3
80 60 90
60
2
85 66
0
5
60 75 90 55 75
75
0
输出
1
0
2
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
int n, a[102], t, x;
int main()
{
    while (cin >> n)
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            a[t]++;
        }
        cin >> x;
        cout << a[x] << endl;
    }

    return 0;
}
