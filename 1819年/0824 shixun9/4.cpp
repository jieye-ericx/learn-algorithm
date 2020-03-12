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
void st(int ,int );
void ed(int ,int );
int vis[5][5];
char bo[5][5];
int i,j,n,sum;
int dir[4][2]={{-1,0},{0,1},{+1,0},{0,-1}};

bool canP(int dx,int dy){
    if(vis[dx][dy]==2) return false;
    if(dx>n||dy>n||dx<1||dy<1) return false;
    else {
        int i;
        for(i=dx-1;i>=1;i--){
            if(vis[i][dy]==1) break;
            else if(vis[i][dy]==3) return false;
        }
        for(i=dx+1;i<=n;i++){
            if(vis[i][dy]==1) break;
            else if(vis[i][dy]==3) return false;
        }
        for(i=dy-1;i>=1;i--){
            if(vis[dx][i]==1) break;
            else if(vis[dx][i]==3) return false;
        }
        for(i=dy+1;i>=1;i--){
            if(vis[dx][i]==1) break;
            else if(vis[dx][i]==3) return false;
        }
        return true;
    }
}

void dfs(int x,int y){


    int cnt1,cnt2,cnt=0,cnt3=0;
    for(cnt1=1;cnt1<=n;cnt1++){
        for(cnt2=1;cnt2<=n;cnt2++){
            if(vis[cnt1][cnt2]) cnt++;
            if(vis[cnt1][cnt2]==3) cnt3++;
        }
    }
    
    if(cnt==n*n){
        if(sum<cnt3) sum=cnt3;
        return;
    }
    for(cnt1=x;cnt1<=n;cnt1++){
        for(cnt2=y;cnt2<=n;cnt2++){
            if(vis[cnt1][cnt2]!=0) continue;
            //if(canP(cnt1,cnt2)){
                st(cnt1,cnt2);
                dfs(cnt1,cnt2);
                ed(cnt1,cnt2);
            //}
        }
    }
    return;
}

void st(int dx,int dy){
    vis[dx][dy]=3;
        for(i=dx-1;i>=1;i--){
            if(vis[i][dy]==1) break;
            else vis[i][dy]=2;
        }
        for(i=dx+1;i<=n;i++){
            if(vis[i][dy]==1) break;
            else vis[i][dy]=2;
        }
        for(i=dy-1;i>=1;i--){
            if(vis[dx][i]==1) break;
            else vis[dx][i]=2;
        }
        for(i=dy+1;i>=1;i--){
            if(vis[dx][i]==1) break;
            else vis[dx][i]=2;
        }
    
}

void ed(int dx,int dy){
    vis[dx][dy]=0;
        for(i=dx-1;i>=1;i--){
            if(vis[i][dy]==1) break;
            else vis[i][dy]=0;
        }
        for(i=dx+1;i<=n;i++){
            if(vis[i][dy]==1) break;
            else vis[i][dy]=0;
        }
        for(i=dy-1;i>=1;i--){
            if(vis[dx][i]==1) break;
            else vis[dx][i]=0;
        }
        for(i=dy+1;i>=1;i--){
            if(vis[dx][i]==1) break;
            else vis[dx][i]=0;
        }
    
}




int main(){
    while(scanf("%d",&n)!=EOF,n){
        memset(vis,0,sizeof(vis));
        sum=0;
        //
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                cin>>bo[i][j];
                if(bo[i][j]=='X') vis[i][j]=1;
            }
        }
        dfs(1,1);
        cout<<sum<<endl;
        }
    system("pause");
    return 0;
}