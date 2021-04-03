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
#define N 200003
int n,i,j,shortcut;
vector<int>g[N];
int dis[N];
int cur,vis[N],now;
int main(){
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        //
        for(i=1;i<=n;i++){
            cin>>shortcut;
            if(shortcut!=i)
                g[i].push_back(shortcut);
        }
        for(i=1;i<=n;i++){
            g[i].push_back(i+1);
            g[i+1].push_back(i);
        }
    
    queue<int>qu;
    
    qu.push(1);
    vis[1]=1;
    dis[1]=0;
    while(!qu.empty()){
        cur=qu.front();
        qu.pop();
        
        for(i=0;i<g[cur].size();i++){
            now=g[cur][i];
            if(vis[now]) continue;
            vis[now]=1;
            dis[now]=dis[cur]+1;
            qu.push(now);
        }
    }
    for(i=1;i<=n;i++){
        cout<<dis[i]<<' ';
    }cout<<endl;
    }
    system("pause");
    return 0;
}
