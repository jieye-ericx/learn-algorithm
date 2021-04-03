#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define N 12
int n,m,t,i,j,c,fx,fy,fz,time;
char a[2][N][N];
int vis[2][N][N];
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
struct node{
    int x,y,z,t;
    node(){}
    node(int x1,int y1,int z1,int t1){
        x=x1;y=y1;z=z1;t=t1;
    }
};

int bfs(){
    queue<node> q;
    int dx,dy,x,y,z,zz,tt;
    q.push(node(0,0,0,0));
    vis[0][0][0]=1;
    while(!q.empty()){
        node now=q.front(); 
        q.pop();
        x=now.x;
        y=now.y;
        z=now.z;
        tt=now.t;
        if(tt>t) continue;
        if(a[z][x][y]=='P') return tt;
        
        for(int i=0;i<4;i++){
            dx=x+dir[i][0],dy=y+dir[i][1],zz=z;
            if(dx<0||dx>=n||dy<0||dy>=m) continue;
            
            if(a[zz][dx][dy]=='#') {
                zz^=1;
                if(a[zz][dx][dy]=='#') continue;
            }
            if(a[zz][dx][dy]=='*') continue;
            if(vis[zz][dx][dy]) continue;
            vis[zz][dx][dy]=1;
            q.push(node(dx,dy,zz,tt+1));
    	}
    }
    return tt;
}

int main(){
	ios::sync_with_stdio(false);
    cin>>c;
    while(c--){
        cin>>n>>m>>t;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[0][i][j];
                if(a[0][i][j]=='P'){
                    fx=i;
                    fy=j;
                    fz=0;
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[1][i][j];
                if(a[1][i][j]=='P'){
                    fx=i;
                    fy=j;
                    fz=1;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        time=bfs();
        if(!time||time>t) printf("NO\n");
        else printf("YES\n");
        //cout<<time<<endl;
    }
    system("pause");
	return 0;
}
