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
#include <queue>
using namespace std;
#define N 106
int n,i,j,cur,now,x,y;
int dis1[N],dis2[N];
int vis[N];
vector<int> g[N];
int main(){
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        memset(dis1,0,sizeof(dis1));
        memset(dis2,0,sizeof(dis2));
        //
        for(i=0;i<n;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        queue<int> qu; 
        qu.push(1);
        dis1[1]=0;
        vis[1]=1;
        while(!qu.empty()){
            cur=qu.front;
            qu.pop();
            for(i=0;i<g[cur].size();i++){
                now=g[cur][i];
                if(vis[now]) continue;
                vis[now]=1;
                dis1[now]=dis1[cur]+1;
                qu.push(now);
            }        
        }
        memset(vis,0,sizeof(vis));
        qu.
        while()

    }
    system("pause");
    return 0;
}
// 题目大意：
// 	有一颗编号从1~N的树，其中第一个结点为黑色，第N个结点为白色，其他结点为无色。
// 	Fennec和Snuke轮流在该树上无色的结点上涂色，Fennec先涂色，且按照如下规则：
// 	Fennec：选择没有着色且与黑色相邻的结点涂色，且涂黑色
// 	Snuke：选择没有着色且与白色相邻的结点涂色，且涂白色
//  	给定一颗树，求谁涂色的点较多。
