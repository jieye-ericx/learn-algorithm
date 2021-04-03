#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define N 10
int a[N],b[N];
int n,m,ans,i,j,t,y,x,flag;
vector<int> g[N];
struct Edge
{
    int u,v;
}e[30];//先将边保存起来最后枚举

bool check(){
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}

void dfs(int dep){
    if(dep>m){
        if(check()){
            ans++;
        }
        return;
    }
    int x=e[dep].u,y=e[dep].v;
    if(a[x]<g[x].size()/2 && a[y]<g[y].size()/2){
        a[x]++;
        a[y]++;
        dfs(dep+1);
        a[x]--;
        a[y]--;
    }
    if(b[x]<g[x].size()/2 && b[y]<g[y].size()/2){
        b[y]++;
        b[x]++;
        dfs(dep+1);
        b[x]--;
        b[y]--;
    }
    
    return;
}



int main(){
    ios::sync_with_stdio(false);
    scanf("%d",&t);
	while(t--){
        // memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<30;i++){
            e[i].u=0;e[i].v=0;
        }
        for(i=1;i<=8;i++) g[i].clear();
        //num=0;
        flag=0;
        ans=0;
        //
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d",&e[i].u,&e[i].v);
            g[e[i].u].push_back(e[i].v);
            g[e[i].v].push_back(e[i].u);
        }
        if(m&1){
            printf("0\n");
            continue;
        }
        for(i=1;i<=n;i++){
            if(g[i].size()&1) {
                flag=1;
                break;}
        }
        if(flag) {
            printf("0\n");
            continue;
        }
        dfs(1);
        printf("%d\n",ans);
	}
    system("pause");
	return 0;
}
