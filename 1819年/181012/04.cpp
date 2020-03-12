#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
#define N 102
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int i,j,k,n,m,to,from;
vector<int> g[N];
void dfs(int cur,int parent){//parent为cur的父节点
    int i,now;
    dis[cur]=dis[parent]+1;
    if(max_dis<dis[cur]){
        max_dis=dis[cur];
        max_index=cur;
    }
    for(i=0;i<g[cur].size();i++){
        now=g[cur][i];
        if(now=parent) continue;
        dfs(now,cur);
    }
}

int main(){
    while(cin>>n&&n){
        for(i=0;i<n;i++){
            cin>>m;
            for(j=0;j<N;j++) g[j].clear();
            for(j=0;j<m;j++){
                cin>>to>>from;
                g[to].push_back(from);
                g[from].push_back(to);
            }
            max_dis=0;
            dis[0]=-1;
            dfs(1,0);
        }

    }
    system("pause");
    return 0;
}
//给定n棵树，每棵树的顶点不超过100，求将这些数连接后所得到的最长链
// 先用dfs找到一棵树的最长链，然后两两相加