/**
 * 
 * 题目描述
按照手机键盘输入字母的方式，计算所花费的时间 如：a,b,c都在“1”键上，输入a只需要按一次，输入c需要连续按三次。 
如果连续两个字符不在同一个按键上，则可直接按，如：ad需要按两下，kz需要按6下 
如果连续两字符在同一个按键上，则两个按键之间需要等一段时间，如ac，在按了a之后，需要等一会儿才能按c。
 现在假设每按一次需要花费一个时间段，等待时间需要花费两个时间段。 现在给出一串字符，需要计算出它所需要花费的时间。
输入描述:
一个长度不大于100的字符串，其中只有手机按键上有的小写字母
输出描述:
输入可能包括多组数据，对于每组数据，输出按出Input所给字符串所需要的时间

输入
bob
www
输出
7
7*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int arr[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
string str;
int sum;
int main()
{
    while (cin >> str)
    {
        sum = arr[str[0] - 'a'];
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] - str[i - 1] == arr[str[i] - 'a'] - arr[str[i - 1] - 'a'])
                sum += 2;
            sum += arr[str[i] - 'a'];
        }
        printf("%d\n", sum);
    }

    return 0;
}
