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
#define N 10000
int n,i,j,maxdis,pi,qi,di,vis[N],farcity;
struct node{
	int dis,length;
	node(int d,int l){
		dis=d;
		length=l;
	}
};
vector<node> g[N];

void dfs(int city,int dist){
	if(dist>maxdis){
		maxdis=dist;
		farcity=city;
	}
	int i;
	for(i=0;i<g[city].size();i++){
		if(vis[g[city][i].dis]) continue;
		vis[g[city][i].dis]=1;
		dfs(g[city][i].dis,dist+g[city][i].length);
		vis[g[city][i].dis]=0;
	}
}
int main(){
	//ios::sync_with_stdio(false);
	maxdis=0;
	farcity=0;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d%d",&pi,&qi,&di);
		g[pi].push_back(node(qi,di));
		g[qi].push_back(node(pi,di));
	}
	// for(i=1;i<n;i++){
	// 	memset(vis,0,sizeof(vis));
	// 	vis[i]=1;
	// 	dfs(i,0);
	// }

	memset(vis,0,sizeof(vis));
	vis[i]=1;
	dfs(i,0);
	memset(vis,0,sizeof(vis));
	vis[farcity]=1;
	dfs(farcity,0);
	printf("%d\n",(maxdis*maxdis+21*maxdis)/2);
//	for(i=1;i<=n;i++){
//		for(j=0;j<g[i].size();j++){
//			printf("%d,%d ",g[i][j].dis,g[i][j].length);
//		}
//		printf("\n");
//	}
system("pause");
	return 0;
}


