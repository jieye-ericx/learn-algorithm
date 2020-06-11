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

int m,n,sum,sx,sy,i,j;
char a[102][102];
int vis[102][102];
int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{+1,0},{1,-1},{0,-1},{-1,-1}};

bool canm(int dx,int dy){
    if(dx<1||dy<1||dx>m||dy>n) return false;
    else if(vis[dx][dy]) return false;
    else if(a[dx][dy]=='*') return false;
    return true;
}

void dfs(int dx,int dy){
    int i,j,cnt=0;
    for(i=0;i<8;i++){
        if(!canm(dx+dir[i][0],dy+dir[i][1])) cnt++;
        else {
            
            vis[dx+dir[i][0]][dy+dir[i][1]]=1;
            dfs(dx+dir[i][0],dy+dir[i][1]);
        }
    }
    if(cnt==8) {
        //sum++;
        return;
    }
}

int main(){
    while(scanf("%d%d",&m,&n),m+n){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        sum=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                //scanf("%s",a[i]);
                cin>>a[i][j];
                //if(a[i][j]=='@') {
                //    sy=j,sx=i;//行/列
                //    vis[sx][sy]=1;
                //}
                if(a[i][j]=='*'){
                    vis[i][j]=1;
                }
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(!vis[i][j]){
                    dfs(i,j);
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    //}
        //for(i=1;i<=m;i++){
        //for(j=1;j<=n;j++){
        //    //scanf("%c",a[i][j]);
        //    cout<<vis[i][j];
        //}cout<<endl;}
    }
    system("pause");
    return 0;
}