#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int n, m, k, ar[1004][1004], dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
struct node
{
    int nn, mm, times;
};
queue<node> myqueue;
void boom(int time)
{
    while (!myqueue.empty())
    {
        node t = myqueue.front();
        if (t.times != time)
        {
            return;
        }
        else
        {
            myqueue.pop();
        }
        t.times += 1;
        int xcol = t.nn, ycol = t.mm;
        for (int i = 0; i < 4; i++)
        {
            t.nn = xcol + dir[i][0];
            t.mm = ycol + dir[i][1];
            if(t.nn>n||t.nn<1||t.mm>m||t.mm<0)
                continue;
            if(ar[t.nn][t.mm]!=1){
                myqueue.push(t);
                ar[t.nn][t.mm] = 1;
            }
        }
    }
}
char st;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> st;
            if (st == '.')
                ar[i][j] = 0;
            else
            {
                node t;
                t.mm = j;
                t.nn = i;
                t.times = 1;
                myqueue.push(t);
                ar[i][j] = 1;
            }
        }
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        boom(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ar[i][j] == 0)
                cout << '.';
            else
                cout << 'g';
        }
        cout << "\n";
    }
    return 0;
}

// 问题描述
// 　　小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
// 　　小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
// 　　这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，
// 则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
// 　　请告诉小明，k 个月后空地上哪些地方有草。
// 输入格式
// 　　输入的第一行包含两个整数 n, m。
// 　　接下来 n 行，每行包含 m 个字母，表示初始的空地状态，字母之间没有空格。
//     如果为小数点，表示为空地，如果字母为 g，表示种了草。
// 　　接下来包含一个整数 k。
// 输出格式
// 　　输出 n 行，每行包含 m 个字母，表示 k 个月后空地的状态。
//    如果为小数点，表示为空地，如果字母为 g，表示长了草。
// 样例输入
// 4 5
// .g...
// .....
// ..g..
// .....
// 2
// 样例输出
// gggg.
// gggg.
// ggggg
// .ggg.
// 评测用例规模与约定
// 　　对于 30% 的评测用例，2 <= n, m <= 20。
// 　　对于 70% 的评测用例，2 <= n, m <= 100。
// 　　对于所有评测用例，2 <= n, m <= 1000，1 <= k <= 1000。