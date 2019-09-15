#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
vector<int> g[10005];
int n,m,i,u,v,vis[10005];
long long ans;

void dfs(int dep,int poi){
	if(dep==3){
		ans++;
		return;
	}
	int t;
	for(t=0;t<g[poi].size();t++){
		if(i==g[poi][t]&&dep==2){
			ans++;
			continue;
		}
		if(vis[g[poi][t]]) continue;
		vis[g[poi][t]]=1;
		dfs(dep+1,g[poi][t]);
		vis[g[poi][t]]=0;
	}
}
//void dfs(int dep,int poi,int pre){
//	if(dep==3){
//		ans++;
//		return;
//	}
//	int t;
//	for(t=0;t<g[poi].size();t++){
//		if(g[poi][t]!=pre)
//		    dfs(dep+1,g[poi][t],poi);
//	}
//}

int main(){
	//ios::sync_with_stdio(false);
	ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(0,i);
	}
	printf("%lld\n",ans);
	return 0;
}


