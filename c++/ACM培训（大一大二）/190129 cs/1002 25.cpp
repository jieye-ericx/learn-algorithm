#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
const int N = 6;
int ans = 0;
int mpt[N+1][N+1];
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
void dfs(int x,int y)
{
    if(x == 0 || y == 0 || x == N || y == N){
        ans ++;
        return;
    }
    for(int i = 0 ; i < 4 ; i ++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(mpt[tx][ty])continue;
        mpt[tx][ty] = 1;
        mpt[N-tx][N-ty] = 1;
        dfs(tx,ty);
        mpt[tx][ty] = 0;
        mpt[N-tx][N-ty] = 0;
    }
}
int main()
{
    mpt[N/2][N/2] = 1;
    dfs(N/2,N/2);
    printf("%d\n",ans/4);
    system("pause");
    return 0;
}
