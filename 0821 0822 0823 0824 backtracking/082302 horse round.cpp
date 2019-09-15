#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
//#include <windows.h>
using namespace std;
#define N 15
int n,x,y,flag=0;
struct point{
    int x,y;
    int num;
    point():num(0){
    }
    bool operator < (point p1) const{
        return num<p1.num;
    }
};
int dir[8][2]={{-2,-1},{-2,1},{2,1},{2,-1},
                {1,2},{1,-2},{-1,2},{-1,-2}};
int vis[N][N]={0};

bool canPut(int dx,int dy){
    if(dx<0 ||dx>=n || dy<0 ||dy>=n)
        return false;
    else if(vis[dx][dy]==1)
        return false;
    
    return true;
}
int canPut_num(int x,int y){
    int dx,dy,cnt=0,i;
    for(i=0;i<8;i++){
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        if(canPut(dx,dy)){
            cnt++;
        }
    }
}
int next(int x,int y,point ne[8]){
    int i,dx,dy,cnt=0;;
    for(i=0;i<8;i++){
        dx=x+dir[i][0];
        dy=y+dir[i][1];
        if(canPut(dx,dy)){
            ne[cnt].x=dx;
            ne[cnt].y=dy;
            ne[cnt].num=canPut_num(dx,dy);
            cnt++;
        }
    }
    sort(ne,ne+cnt);
    return cnt;
}

void dfs(int x,int y,int dep){
    int i,dx,dy,k;
    point ne[8];
    if(flag) return;
    if(dep>n*n-1){
        cout<<"YES"<<endl;
        flag=1;
        return ;
    }
    k=next(x,y,ne);
    for(i=0;i<k;i++){
        dx=ne[i].x;
        dy=ne[i].y;
        if(canPut(dx,dy)){
            vis[dx][dy]=1;
            dfs(dx,dy,dep+1);
            vis[dx][dy]=0;
        }
    }


    //for(i=0;i<8;i++){
    //    dx=x+dir[i][0];
    //    dy=y+dir[i][1];
    //    if(canPut(dx,dy)){
    //        vis[dx][dy]=1;
    //        dfs(dx,dy,dep+1);
    //        vis[dx][dy]=0;
    //    }

    
}

int main(){
    scanf("%d",&n);
    cin>>x>>y;
    vis[x][y]=1;
    dfs(x,y,1);

    system("pause");
    return 0;
}