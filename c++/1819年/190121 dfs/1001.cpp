#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 21
char s;
int a[N][N],vis[N][N];
int w,h,i,j,num,dx,dy;


void dfs(int x,int y){
    if(x>=h||x<0||y>=w||y<0) return;
    if(!a[x][y]) return;
    if(vis[x][y]) return;
    vis[x][y]=1;
    dfs(x,y+1);
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y-1);
}

int main(){
	while(scanf("%d%d",&w,&h)!=EOF,w){
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        num=0;
        //
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                //scanf("%c",&s);
                cin>>s;
                if(s=='#') a[i][j]=0;
                else if(s=='.') a[i][j]=1;
                else {
                    a[i][j]=1;
                    dx=i;
                    dy=j;
                    //vis[i][j]=1;
                }
            }
        }
        // for(i=0;i<h;i++){
        //     for(j=0;j<w;j++){
        //         cout<<a[i][j];
        //     }
        //     cout<<"\n";
        // }
        dfs(dx,dy);
		for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if(vis[i][j]) num++;
            }
        }
        printf("%d\n",num);
	}
	return 0;
}
