#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define N 100004
vector<int> g[N],m;
int n,a,b,i,k,vis[N];
queue<int> q;
stack<int> s;

bool check(){
	int t=s.top();
	for(int i=s.size()-2;i>=0;i--){
		
	}
	
}
int main(){
	//ios::sync_with_stdio(false);
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	q.push(g[1][0]);
	vis[1]=1;
	while(!q.empty()){
		k=q.front();
		q.pop();
		if(vis[k]&&s.top()!=k) break;
		
		
		
		if(vis[k]) continue;
		vis[k]=1;
		for(i=0;i<g[k].size();i++){
			q.push(g[k][i]);
		}
		
	}
	return 0;
}


