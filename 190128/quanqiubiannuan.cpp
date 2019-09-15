#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define N 10
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int vis[N][N];
char a[N][N];
int n,i,j,num,cur,flag;

struct node{
    int x,y;
    node(int a,int b){
        x=a,y=b;
    }
};


void bfs(int x,int y){
    flag=0;
    queue<node> q;
    q.push(node(x,y));
    int i,j,dx,dy,cnt;
    while(!q.empty()){
        node now=q.front();
        q.pop();
        cnt=0;
        for(i=0;i<4;i++){
            dx=now.x+dir[i][0],dy=now.y+dir[i][1];
            if(a[dx][dy]=='#') cnt++;
            else break;
        }
        if(cnt==4&&flag==0){
            cur++;
            flag=1;
        }
        for(i=0;i<4;i++){
            dx=now.x+dir[i][0],dy=now.y+dir[i][1];
            if(dx>n||dx<0||dy>n||dy<0) continue;
            if(vis[dx][dy]) continue;
            if(a[dx][dy]=='.') continue;
            vis[dx][dy]=1;
            q.push(node(dx,dy));
        }

    }
    
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        num=0;
        cur=0;;
        //
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j]=='.') vis[i][j]=1;
            }  
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if(!vis[i][j]) {
                    num++;
                    bfs(i,j);
                }
            }   
        cout<<num-cur<<endl;
    }
    system("pause");
	return 0;
}
