#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int isHappy(int n);
int getNext(int nowAns);
int T;
int main()
{
    // cin >> T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        // cin >> n;
        scanf("%d", &n);
        printf("%d\n", isHappy(n));
        // cout << isHappy(n) << '\n';
    }
    return 0;
}

//! oj
int isHappy(int n)
{
    int vis[800], cnt = 0, nextNum = n;
    memset(vis, 0, sizeof(vis));
    while (1)
    {
        nextNum = getNext(nextNum);
        if (nextNum == 1)
            return cnt + 1;
        if (vis[nextNum])
            return -1;
        vis[nextNum] = 1;
        // cout << "nextNum: " << nextNum << "cnt: " << cnt << endl;
        cnt++;
    }
}

int getNext(int nowAns)
{
    int tmpAns = 0;
    while (nowAns > 0)
    {
        tmpAns += pow(nowAns % 10, 2);
        nowAns /= 10;
    }
    return tmpAns;
}

//! leet
bool isHappy1(int n)
{
    int tmpAns, nowAns = n, tmpNum;
    int vis[800];
    memset(vis, 0, sizeof(vis));
    while (1)
    {
        tmpAns = 0;
        while (nowAns > 0)
        {
            tmpNum = nowAns % 10;
            tmpAns += pow(tmpNum, 2);
            nowAns /= 10;
        }
        if (tmpAns == 1)
        {
            return true;
        }
        nowAns = tmpAns;
        if (vis[nowAns])
            return false;
        vis[nowAns] = 1;
        cout << "tmpAns?: " << tmpAns << endl;
    }
    return false;
}