#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>啦
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
#define N 102
#define INF 0x3f3f3f3f
vector<int>g[N];
int n,m;//n:顶点数量m:边的数量
int i,j,x,y;
int vis[N]={0},dis[N];//dis用于计算点之间的的距离
int dfs_num[N],cnt=1;
int dfs(int cur){//cur=current当前的点  
    int i,k;
    vis[cur]=1;
    dfs_num[cur]=cnt++;//dfs编号
    for(i=0;i<g[cur].size();i++){
        k=g[cur][i];//k表示与cur相邻的顶点编号
        if(!vis[k]){
            //dis[k]=dis[cur]+1;
            for(j=0;j<g[k].size();j++){
                dis[k]=min(dis[k],dis[g[k][j]]+1);
            }
            dfs(k);
        }
        
        
    }
}
int main(){
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>x>>y;
        //cin>>x>>y>>w;
        //如果有权重的话就用这种输入方式
        //同时vector需要改为vector<pair<int,int>>g[N]
        g[x].push_back(y);
        g[y].push_back(x);//此方法为无向图，所以同时插入y到x的路线
    }
    for(i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[1]=0;
    dfs(1);
    
    system("pause");
    return 0;
}

