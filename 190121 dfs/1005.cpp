#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 21
int vis[N],rec[N];
int n,i,j;
int prime[40]={0,1,1,1,0,1, 0,1,0,0,0, 1,0,1,0,0, 0,1,0,1,0, 0,0,1,0,0, 0,0,0,1,0, 1,0,0,0,0,0,1, 0,1};

void dfs(int dep){
    int t,i;
    if(dep>=n){
        if(prime[rec[dep]+rec[1]]==1){
            for(i=1;i<=n;i++){
                printf("%d",rec[i]);
                if(i!=n) printf(" ");
            }printf("\n");
            return;
        }
    }
    for(t=1;t<=n;t++){
        if(vis[t]==0&&prime[rec[dep]+t]==1) {
            vis[t]=1;
            rec[dep+1]=t;
            dfs(dep+1);
            vis[t]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    j=0;
    while(cin>>n){
        printf("Case %d:\n",++j);
        memset(rec,0,sizeof(rec));
        memset(vis,0,sizeof(vis));
        rec[1]=1;
        vis[1]=1;
        // 
        dfs(1);   
        printf("\n");    
    }
	return 0;
}
