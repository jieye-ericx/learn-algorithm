//剪格子
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
#define N 12
// struct node
// {
//     int index;
//     int value;
// };
// node temp;
// vector<node>g[N];
//vector<pair<int,int>>g1[N];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int g[N][N],vis[N][N],vis1[N][N];

int i,j,sum,v,m,n,ret,num,sum1,s1;

// void dfs1(int x,int y){
//     s1++;
//     for(){
//         dx,dy=;
//         if(vis[dx][dy]&&!vis1[dx][dy]){
//             continue;
//         }

//     }
// }
int judge(int s){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!vis[i][j]){
                memset(vis1,0,sizeof(vis1));
                s1=0;
            }
        }
    }
}

void dfs(int x,int y,int s,int len){
    int i,dx,dy;
    // if(vis[x][y]) return;
    if(s>sum) return;
    if(s==sum&&judge(len)){
        if(ret>len) ret=len;
        return;
    } //检查

    for(i=0;i<4;i++){
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        if(vis[dx][dy]) continue;
        if(dx<0||dy<0||dx>=n||dy>=m) continue;
        vis[x][y]=1;
        dfs(dx,dy,s+g[dx][dy],len+1);
        vis[x][y]=0;
        // now=p.first;
        // v=p.second;
        // if(now==par) continue;
        // dis[now]=dis[cur]+v;
        // dfs(now,cur);//回退
    }
}

int main(){
    while(cin>>m>>n){
        sum=0;ret=999999;
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));

        //
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>g[i][j];
                sum+=g[i][j];
            }
            // temp.index=from;
            // temp.value=v;
            // g[to].push_back(temp);
            // temp.index=to;
            // g[from].push_back(temp);
            // //
            // temp=make_pair(from,v);
            // g1[to].push_back(temp);
            // g1[from].push_back(make_pair(to,v));
        }
        if(sum&1) cout<<"0"<<endl;
        else{
            sum>>=1;
            dfs(0,0,g[0][0],1);
            cout<<ret<<endl;
        }
    }
    
    system("pause");
    return 0;
}
/*
3 3
10 1 52 
20 30 1
1 2 3
*/