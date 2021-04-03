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
// #define N 10
#define INF 0x3f3f3f3f
#define N 502
char g[N][N];
int vis[N][N]={0};
int n1,n,m,k;
int i,j,k,sx,sy,cnt;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y){
    int i,j,dx,dy;
    vis[dx][dy]=1;
    cnt++;
    if(cnt>=n1-k){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(g[][j]=='.'&&vis[i][j]==0){
                    cout<<'X';
                }else{
                    cout<<g[i][j];
                }
            }
        }
        return;
    }
    for(i=0;i<4;i++){
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        if(dx<0||dx>=n||dy<0||dy>=m) continue;
        if(g[dx][dy]=='#'||vis[dx][dy]) continue;
        
        dfs(dx,dy);
    }
}
int main(){
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        cin>>g[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(g[i][j]=='.'){
                n1++;
                sx=i;
                sy=j;
            }
        }
    }
    dfs(sx,sy);
}
/////////////////刘冠迪
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
// #define N 10
#define INF 0x3f3f3f3f
#define N 502
char g[N][N];
int vis[N][N]={0};
int n1,n,m,k;
int i,j,k,sx,sy,cnt;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y){
    int i,j,dx,dy;
    vis[dx][dy]=1;
    
    if(cnt>=k){
        
        return;
    }
    for(i=0;i<4;i++){
        dx=x+dir[i][0];
        dy=y+dir[i][1]; 
        if(dx<0||dx>=n||dy<0||dy>=m) continue;
        if(g[dx][dy]=='#'||vis[dx][dy]) continue;
        
        dfs(dx,dy);
        cnt++;
        if(cnt<=k) g[dx][dy]='X';
    }
}
int main(){
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        cin>>g[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(g[i][j]=='.'){
                n1++;
                sx=i;
                sy=j;
            }
        }
    }
    dfs(sx,sy);
}