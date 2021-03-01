/*
一根长度为1米的木棒上有若干只蚂蚁在爬动。它们的速度为每秒一厘米或静止不动，方向只有两种，向左或者向右。
如果两只蚂蚁碰头，则它们立即交换速度并继续爬动。
三只蚂蚁碰头，则两边的蚂蚁交换速度，中间的蚂蚁仍然静止。如果它们爬到了木棒的边缘（0或100厘米处）则会从木棒上坠落下去。
在某一时刻蚂蚁的位置各不相同且均在整数厘米处（即1，2，3，…99厘米），
有且只有一只蚂蚁A速度为0，其他蚂蚁均在向左或向右爬动。
给出该时刻木棒上的所有蚂蚁位置和初始速度，找出蚂蚁A从此时刻到坠落所需要的时间。
输入描述:
    第一行包含一个整数表示蚂蚁的个数N（2<=N<=99），之后共有N行，每一行描述一只蚂蚁的初始状态。
    每个初始状态由两个整数组成，中间用空格隔开，第一个数字表示初始位置厘米数P（1<=P<=99），
    第二个数字表示初始方向,-1表示向左，1表示向右，0表示静止。
输出描述:
    蚂蚁A从开始到坠落的时间。若不会坠落，输出“Cannot fall!”

输入
4
10 1
90 0
95 -1
98 -1
输出
98
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
struct ant
{
    int pos, dir;
    ant(int pos, int dir)
        : pos(pos), dir(dir)
    {
    }
};
bool tmp(ant a, ant b)
{
    return a.pos < b.pos;
};
vector<ant> ants;
int n, p, d;
int main()
{
    while (scanf("%d", &n) != EOF)
    {

        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &p, &d);
            ants.push_back(ant(p, d));
        }
        sort(ants.begin(), ants.end(), tmp);
        int ll = 0, lr = 0, rl = 0, rr = 0, flag = 0;
        vector<ant>::iterator comp;
        for (int it = 0; it < n; it++)
        {
            if (ants[it].dir == -1)
                ll++;
            if (ants[it].dir == 0)
                flag = it; //左边有it只蚂蚁
        }
        //循环后得到总共向左有ll只，A蚂蚁左边有flag只；
        // cout << flag << " " << ll << endl;
        if (flag == ll)
            printf("Cannot fall!\n");
        else if (flag > ll) //向右
        {
            int cnt = 0;
            for (int i = n - 1; i > 0; i--)
            {
                if (ants[i].dir == 1)
                    cnt++;
                if (cnt == n - flag)
                {
                    printf("%d\n", 100 - ants[i].pos);
                    break;
                }
            }
        }
        else
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (ants[i].dir == -1)
                    cnt++;
                if (cnt == flag + 1)
                {
                    printf("%d\n", ants[i].pos);
                    break;
                }
            }
        }
    };
    return 0;
}
