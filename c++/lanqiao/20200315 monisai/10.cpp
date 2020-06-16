#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int n, m;

struct node
{
    int deep;
    int id;
} nodes[100005];

bool cmp1(node a, node b)
{
    return a.deep > b.deep;
}

bool cmp2(node a, node b)
{
    return a.id < b.id;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].deep;
        nodes[i].id = i;
    }
    sort(nodes, nodes+n, cmp1);
    sort(nodes, nodes + m, cmp2);

    cout << nodes[0].deep;
    for (int i = 1; i < m; i++)
    {
        cout << " "<<nodes[i].deep;
    }
    cout << "\n";
    return 0;
}
/*
问题描述
　　小明要组织一台晚会，总共准备了 n 个节目。然后晚会的时间有限，他只能最终选择其中的 m 个节目。
　　这 n 个节目是按照小明设想的顺序给定的，顺序不能改变。
　　小明发现，观众对于晚上的喜欢程度与前几个节目的好看程度有非常大的关系，他希望选出的第一个节目尽可能好看，在此前提下希望第二个节目尽可能好看，依次类推。
　　小明给每个节目定义了一个好看值，请你帮助小明选择出 m 个节目，满足他的要求。
输入格式
　　输入的第一行包含两个整数 n, m ，表示节目的数量和要选择的数量。
　　第二行包含 n 个整数，依次为每个节目的好看值。
输出格式
　　输出一行包含 m 个整数，为选出的节目的好看值。
样例输入
5 3
3 1 2 5 4
样例输出
3 5 4
样例说明
　　选择了第1, 4, 5个节目。
评测用例规模与约定
　　对于 30% 的评测用例，1 <= n <= 20；
　　对于 60% 的评测用例，1 <= n <= 100；
　　对于所有评测用例，1 <= n <= 100000，0 <= 节目的好看值 <= 100000。
请选择编程语言

*/