#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define N 103
char a[N][N];
int vis[N][N];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,t,i,j,k,x1,x2,yy,y2,time;

struct node{
    int x,y,t,dir;//以上四个方向分别为1，2，3，4
    node(){}
    node(int x1,int yy,int t1,int dir1){
        x=x1;y=yy;t=t1;dir=dir1;
    }
};

int bfs(){
    queue<node> q;
    int dx,dy,fx,fy,ft,fdir;
    q.push(node(x1,yy,0,0));
    vis[x1][yy]=1;
    while(!q.empty()){
        node now=q.front(); 
        q.pop();
        fx=now.x,fy=now.y,ft=now.t,fdir=now.dir;
        cout<<fx<<" "<<fy<<" "<<ft<<" "<<fdir<<" "<<endl;
        if(ft>k){
            vis[fx][fy]=0;
            continue;
        }
        if(fx==x2&&fy==y2) return ft;
        
        for(int i=0;i<4;i++){
            dx=fx+dir[i][0],dy=fy+dir[i][1];
            if(dx<=0||dx>n||dy<=0||dy>m) continue;
            if(a[dx][dy]=='*') continue;
            if(vis[dx][dy]) continue;
            if(i+1!=fdir&&fdir!=0) {
                if(ft+1>k) continue;
                q.push(node(dx,dy,ft+1,i+1));
            }else if(!fdir) q.push(node(dx,dy,ft,i+1));
            else q.push(node(dx,dy,ft,fdir));
            vis[dx][dy]=1;
    	}
    }
    return 0;
}

int main(){
	ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        //
        cin>>m>>n;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        cin>>k>>yy>>x1>>y2>>x2;
        if(k<0||x1<1||yy<1||x2<1||y2<1||x1>n||yy>m||x2>n||y2>m){
            printf("no\n");
        }else{
            time=bfs();
            if(!time||time>k) printf("no\n");
            else printf("yes\n");
        }
        
        //cout<<time<<endl;
    }
    system("pause");
	return 0;
}
