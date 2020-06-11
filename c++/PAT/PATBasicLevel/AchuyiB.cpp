// 题目描述
// 本题要求计算A / B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，
// 使得A = B * Q + R成立。

// 输入描述
// 输入在1行中依次给出A和B，中间以1空格分隔。

// 输出描述
// 在1行中依次输出Q和R，中间以1空格分隔。

// 输入例子 : 123456789050987654321 7
// 输出例子 : 17636684150141093474 3
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ctype.h>
using namespace std;

int main()
{
    string A = "";
    int B;
    cin >> A >> B;
    string Q = "";
    int R = 0;

    int cur = 0;
    bool flag = 0;

    for (int i = 0; i < A.length(); i++)
    {
        cur = cur * 10 + (A[i] - '0');//从前往后模拟除法，每往低位移一位则余数*10+新的低一位的值
        if (flag == 0 && cur / B == 0)//如果当前数小于除数且flag=0，说明整个被除数小于除数
            continue;
        else
            flag = 1;
        char ch = '0' + cur / B;
        Q = Q + ch;
        cur = cur % B;
    }
    if (flag == 0)
        Q = "0";
    cout << Q << ' ' << cur << endl;

    return 0;
}
