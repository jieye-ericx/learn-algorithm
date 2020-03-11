#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
#define N 102
char g[N][N];
int vis[N][N],dir[8][2]={{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
int n,m,i,j,ret;
int dfs(int x,int y){
    int i,dx,dy;
    for(i=0;i<8;i++){
        dy=y+dir[i][1];
        dx=x+dir[i][0];
        // if(dx<0...) continue; //剪枝
        if(!vis[dx][dy]&&g[dx][dy]=='@'){
            vis[dx][dy]=1;
            dfs(dx,dy);
        }
    }
}
int main(){
    while(cin>>n>>m){
        ret=0;
        memset(vis,0,sizeof(vis));
        //
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>g[i][j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(!vis[i][j]&&g[i][j]=='@'){
                    ret++;
                    dfs(i,j);
                }
            }
        }
    }
    system("pause");
    return 0;
}