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
#define N 9

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map1[N][N];
int vis[N][N]={0};

int n,m,t,i,j,sx,sy,ex,ey;
char ch;

bool canMove(int x,int y,int cor){
    if(x<0||x>=n||y<0||y>=m||vis[x][y])
        return false;
    else if(map1[x][y]=='X'){
        return false;
    }else if(x==ex&&y==ey&&t-cor!=1){
        return false;
    }/*else if(abs(x-ex)+abs(y-ey)>t-cor){
        return false;
    }else if(((x+y)&1)^((ex+ey)&1)^((t-cor)&1)){//奇偶剪枝
        return false;
    }*/
    return true;
}

int dfs(int x,int y,int dep){
    
    if(x==ex && y==ey && dep==t) {
        return 1;
    }
    int i,dx,dy;
    for(i=0;i<4;i++){
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        if(!canMove(dx,dy,dep)){
            continue;
        }else {
            vis[dx][dy]=1;
            if(dfs(dx,dy,dep+1))
                return 1;
            vis[dx][dy]=0;
        }
    }
    return 0;

}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m>>t,m+n+t){
        memset(vis,0,sizeof(vis));
        //////////////////
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>ch;
                map1[i][j]=ch;
                if(ch=='S'){
                    sx=i;
                    sy=j;
                }else if(ch=='D'){
                    ex=i;
                    ey=j;
                }
            }
        }
        vis[sx][sy]=1;
        //if(!canMove(sx,sy,t)){
        //    cout<<"No"<<endl;
        //    continue;
        //}
        if(dfs(sx,sy,0))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    system("pause");
    return 0;
}