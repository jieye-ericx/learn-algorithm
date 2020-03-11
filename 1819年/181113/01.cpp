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
#define N 1002
int g[N][N];
int n,m;
int vis[N][N][4],dir[4][2]={-1,0,0,1,1,0,0,-1};//第三列表示旋转次数
struct node
{
    int x;
    int y;
    int rots;
    int len;
    node():rots(0),len(0){
    }
    node(int x1,int y1,int r1,int l1):x(1),y(1),rots(r1),len(l1){

    }
};

int convert(char ch){
    switch(ch){
        case '+':return 15;break;
        case '-':return 5;break;
        case '*':return 0;break;
        case '^':return 8;break;
        ///等等共16种
    }
}

int main(){
    int i,j,st_x,st_y,en_x,en_y,x,y,dx,dy,rot;
    char ch;
    queue<node>qu;
    node n1;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for( j = 0; j < m; j++){
            cin>>ch;
            g[i][j]=convert(ch);
        }
    }
    cin>>st_x>>st_y>>en_x>>en_y;
    qu.push(node(st_x,st_y,0,0));
    vis[st_x][st_y][0]=1;
    while(!qu.empty()){
        n1=qu.front();
        qu.pop;
        x=n1.x;
        y=n1.y;
        rot=n1.rots;
        if(x==en_x&&y==en_y) break;
        for(i=0;i<4;i++){
            dx=x+dir[i][0];
            dy=y+dir[i][1];
            if(vis[dx][dy][rot]){ 
                rot=n1.len;    
                continue;
            }
            if(( g[x][y]>>rot+(g[x][y]<<(4-i))%16&(1<<i) ) && (g[dx][dy] & (1<<((i+2)%4)))){
                qu.push(node(dx,dy,rot,n1.len+1));
                vis[dx][dy][rot]=1;
            }
        }
        if(vis[x][y][(rot+1)%4]) continue;
        qu.push(node(x,y,(rot+1)%4,n1.len));
    }
    if(qu.empty()) cout<<'-1';
    else cout<<
    system("pause");
    return 0;
}