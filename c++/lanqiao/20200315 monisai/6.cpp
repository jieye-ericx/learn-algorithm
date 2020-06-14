#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
//a 97 z 122
int yuanyin[5] = {97, 101, 105, 111, 117};
bool che(char a)
{
    for (int i = 0; i < 5; i++)
    {
        if (a == yuanyin[i])
            return true;
    }
    return false;
}
string x;
int main()
{
    cin >> x;
    int i;
    if (che(x[0])) //第一段开始检查是否为辅音
    {
        cout << "no\n";
        return 0;
    }
    for (i = 1; i < x.size(); i++)
    {
        if (che(x[i]))
        {
            break;
        }
    }
    if (i > x.size() - 2)
    {
        cout << "no\n";
        return 0;
    }
    for (i=i+1; i < x.size(); i++)//第二段跳过元音
    {
        if (!che(x[i]))
        {
            break;
        }
    }
    if (i > x.size() - 2)
    {
        cout << "no\n";
        return 0;
    }
    for (i = i + 1; i < x.size(); i++) //第3段跳过辅音
    {
        if (che(x[i]))
        {
            break;
        }
    }
    if (i > x.size() - 2)
    {
        cout << "no\n";
        return 0;
    }
    for (i = i + 1; i < x.size(); i++) //第4段跳过元音
    {
        if (!che(x[i]))
        {
            break;
        }
    }
    if(i!=x.size()){
        cout << "no\n";
    }else
        cout << "yes\n";
    return 0;
}
/*
问题描述
　　小明对类似于 hello 这种单词非常感兴趣，这种单词可以正好分为四段，第一段由一个或多个辅音字母组成，
第二段由一个或多个元音字母组成，第三段由一个或多个辅音字母组成，第四段由一个或多个元音字母组成。
　　给定一个单词，请判断这个单词是否也是这种单词，如果是请输出yes，否则请输出no。
　　元音字母包括 a, e, i, o, u，共五个，其他均为辅音字母。
输入格式
　　输入一行，包含一个单词，单词中只包含小写英文字母。
输出格式
　　输出答案，或者为yes，或者为no。
样例输入
lanqiao
样例输出
yes
样例输入
world
样例输出
no
评测用例规模与约定
　　对于所有评测用例，单词中的字母个数不超过100。
*/
