#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
struct mpath
{
    int to, cos;
    mpath(int tos, int coss)
    {
        to = tos;
        cos = coss;
    }
};

int sta[505], vis[505], pa[505], laspa[505], minsent = 0xffffff, mintim = 0xffffff, minba = 0xffffff;
int CMAX, N, SP, M, t, si, sj, tij;
void coyy()
{
    for (int i = 0;; i++)
    {
        laspa[i] = pa[i];
        if (pa[i] == SP)
            break;
    }
}
vector<mpath> CC[205];
int dfs(int dep, int cur, int tim, int bnu)
{
    if (cur == SP)
    {
        int sent, back;
        bnu += (sta[cur] - CMAX / 2);
        if (bnu >= 0)
        {
            sent = 0;
            back = bnu;
        }
        else
        {
            back = 0;
            sent = -bnu;
        }

        if (tim < mintim)
        {
            mintim = tim;
            minsent = sent;
            minba = back;
            coyy();
        }
        else if (tim == mintim)
        {
            if (minsent > sent)
            {
                minsent = sent;
                minba = back;
                coyy();
            }
            else if (minsent == sent)
            {
                if (minba > back)
                {
                    minba = back;
                    coyy();
                }
            }
        }
        return 0;
    }
    if (sta[cur] != (CMAX / 2))
    {
        bnu += (sta[cur] - CMAX / 2);
    }
    for (int i = 0; i < CC[cur].size(); i++)
    {
        if (vis[CC[cur][i].to] == 1)
            continue;
        vis[CC[cur][i].to] = 1;
        pa[dep] = CC[cur][i].to;
        dfs(dep + 1, CC[cur][i].to, tim + CC[cur][i].cos, bnu);
        vis[CC[cur][i].to] = 0;
    }
    return 0;
}
int main()
{
    //偶数，每个车站最大容量
    //车站数量
    //问题车站index
    //路的数量
    while (cin >> CMAX >> N >> SP >> M)
    {
        memset(pa, 0, sizeof(pa));
        memset(vis, 0, sizeof(vis));
        memset(sta, 0, sizeof(sta));
        memset(laspa, 0, sizeof(laspa));
        sta[0] = CMAX / 2;
        vis[0] = 1;
        for (int i = 1; i <= N; i++)
        {
            cin >> t;
            sta[i] = t;
        }
        for (int i = 1; i <= M; i++)
        {
            cin >> si >> sj >> tij;
            CC[si].push_back({sj, tij});
            CC[sj].push_back({si, tij});
        }
        dfs(0, 0, 0, 0);
        cout << minsent << " 0";
        for (int i = 0;; i++)
        {
            cout << "->" << laspa[i];
            if (laspa[i] == SP)
                break;
        }

        cout << " " << minba << "\n";
    }

    return 0;
}
