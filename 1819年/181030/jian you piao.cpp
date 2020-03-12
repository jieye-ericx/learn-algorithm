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
struct node{
    int data;
    int paraent;
    int rank;//权重
}uf[N];


int find(int x){
    int k=x,k1;
    while(k!=uf[k].paraent){
        k=uf[k].paraent;
    }
    //-----------将一路上遇到的父节点都改为根节点（k为根节点
    while(x!=uf[x].paraent){
        k1=uf[x].paraent;
        uf[x].paraent=k;
        x=k1;
    }
    return k;
}

int Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        if(uf[x].rank < uf[y].rank){
        uf[x].paraent=y;
        }else{
            uf[y].paraent=x;
            if(uf[x].rank==uf[y].rank){
                uf[x].rank++;
            }
        }
        return 0;
    }
    return 1;
}
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
        for(i=0;i<3;i++)
        for(j=0;j<4;j++){
                cin>>g[i][j];
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