// //剪格子
// #include <cmath>
// #include <iostream>
// #include <cstring>
// #include <string>
// #include <algorithm>
// #include <cstdio>
// #include <vector>
// #include <set>
// #include <map>
// #include <functional>
// using namespace std;
// #define N 10003
// vector<int>g[N];
// int vis[N];
// int i,j,n,m,k,u,v,ret;

// void dfs(int st,int cur,int len){
//     int i,now;
//     if(len==4){
//         ret++;
//         return;
//     }else if(len==3){
//         for(i=0;i<g[cur].size();i++){
//             now=g[cur][i];
//             if(!vis[now]){
//                 ret++;
//                 return;
//             }else if(vis[now]&&now==st){
//                 ret++;
//                 return;
//             }
//         }
//     }else if(len<3){
//         for(i=0;i<g[cur].size();i++){
//             now=g[cur][i];
//             if(!vis[now]){
//                 vis[now]=1;
//                 dfs(st,now,len+1);
//                 vis[now]=0;
//                 return;
//             }else if(vis[now]&&now==st){
//                 ret++;
//                 return;
//             }
//         }
//     }
//     for(i=0;i<g[cur].size();i++){
//         now=g[cur][i];
//         if(!vis[now]){
//             vis[now]=1;
//             dfs(st,now,len+1);
//             // vis[now]
//         }
//     }
// }

// int main(){
//     while(cin>>n>>m){
//         for(i=0;i<m;i++){
//             cin>>u>>v;
//         }
//         for(i=1;i<=n;i++){
//             memset(vis,0,sizeof(vis));
//             dfs(i,cur,1);
//         }
//     }
//     system("pause");
//     return 0;
// }
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
#define N 10003
vector<int>g[N];
int vis[N];
int i,j,n,m,k,u,v,ret;

// void dfs(int st,int cur,int len){
//     int i,now;
//     if(len==4){
//         ret++;
//         return;
//     }else if(len==3){
//         for(i=0;i<g[cur].size();i++){
//             now=g[cur][i];
//             if(!vis[now]){
//                 ret++;
//                 return;
//             }else if(vis[now]&&now==st){
//                 ret++;
//                 return;
//             }
//         }
//     }else if(len<3){
//         for(i=0;i<g[cur].size();i++){
//             now=g[cur][i];
//             if(!vis[now]){
//                 vis[now]=1;
//                 dfs(st,now,len+1);
//                 vis[now]=0;
//                 return;
//             }else if(vis[now]&&now==st){
//                 ret++;
//                 return;
//             }
//         }
//     }
//     for(i=0;i<g[cur].size();i++){
//         now=g[cur][i];
//         if(!vis[now]){
//             vis[now]=1;
//             dfs(st,now,len+1);
//             // vis[now]
//         }
//     }
// }

int main(){
    while(cin>>n>>m){
        for(i=0;i<m;i++){
            //
        }
        for(i=1;i<=n;i++){
            for(j=0;j<g[i].size();j++){
                now=g[i][j];
                ret+=(g[i].size()-1)*(g[now].size()-1);
            }
        }
    }
    system("pause");
    return 0;
}