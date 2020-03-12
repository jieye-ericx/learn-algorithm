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

int n,m,t,sum,i,j,flag;
vector<int> g[12];
int vis[10005];

int gsum(vector<int> y){
    int c=0;
    for(vector<int>::iterator it=y.begin();it!=y.end();it++){
        c+=*it;
    }
    return c;
}

void dfs(int p){
    if(p==m+1){
        printf("YES\n");
        flag=1;
        for(int i=1;i<=m;i++){
            cout<<g[i].size();
            for(vector<int>::iterator it=g[i].begin();it!=g[i].end();it++){
                printf(" %d",*it);
            }
            if(i!=m) printf("\n");
        }
        return;
    }
    if(gsum(g[p])==sum){
        dfs(p+1);
        if(flag) return;
        return;
    }
    if(flag) return;
    for(int i=1;i<=n;i++){
        if(flag) return;
        if(!vis[i]){
            if(gsum(g[p])+i>sum ) continue;
            vis[i]=1;
            g[p].push_back(i);
            dfs(p);
            g[p].pop_back();
            vis[i]=0;
        }
    }
}
int main() {
    //ios::sync_with_stdio(false);
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        for(i=0;i<12;i++) g[i].clear();
        flag=0;
        //
        scanf("%d%d",&n,&m);
        sum=(1+n)*n/2;
        if(sum%m!=0||sum/m<n) {
            printf("NO\n");
            continue;
        }
        sum/=m;
        dfs(1);
        if(t!=0)
            printf("\n");
    }

    //system("pause");
    return 0;
}
