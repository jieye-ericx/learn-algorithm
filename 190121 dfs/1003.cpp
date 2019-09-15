#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 105
char a[N][N];
int vis[N][N];
int w,h,i,j,num,t;
//int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dir[8][2]={{0,1},{1,0},{1,1},{-1,-1},{-1,0},{0,-1},{1,-1},{-1,1}};

void dfs(int x,int y){
    if(x>=h||x<0||y>=w||y<0) return;
    if(vis[x][y]) return;
    if(a[x][y]=='*') return;
    vis[x][y]=1;
    int i;
    for(i=0;i<8;i++){
        dfs(x+dir[i][0],y+dir[i][1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    //scanf("%d",&t);
	while(cin>>h>>w,h){//scanf("%d%d",&h,&w)!=EOF,h){
        memset(vis,0,sizeof(vis));
        num=0;
        //
        // getchar();
        //getchar();
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                //scanf("%c",&a[i][j]);
                cin>>a[i][j];
            }
            //getchar();
        }
        // for(i=0;i<h;i++){
        //     for(j=0;j<w;j++){
        //         printf("%c",a[i][j]);
        //     }
        //     printf("\n");
        // }
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if(a[i][j]=='@'&&vis[i][j]==0){
                    num++;
                    dfs(i,j);
                }
            }
        }
        // for(i=0;i<h;i++){
        //     for(j=0;j<w;j++){
        //         cout<<a[i][j];
        //     }
        //     cout<<"\n";
        // }
        printf("%d\n",num);
        //getchar();
	}
    system("pause");
	return 0;
}
