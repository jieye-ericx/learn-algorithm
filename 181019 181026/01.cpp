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
#define N 100002
vector<int>g[N];
int parent[N],dis[N];
int n,i,j,k,num;
void dfs(int cur,int par){
    int i,now;
    dis[cur]=dis[par]+1;
    for(i=0;i<g[cur].size();i++){
        now=g[cur][i];
        parent[now]=cur;
        if(now==par) continue;
        dfs(now,cur);
    }
}
void dfs1(int cur,int par){
    int i,now;
    // int num;
    num++;
    for(i=0;i<g[cur].size();i++){
        if(now==par) continue;
        dfs(now,cur);
    }
}
int main(){
    int to,par,from,k,cur,cnt;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>to>>from;
        g[to].push_back(from);
        g[from].push_back(to);
    }
    dis[0]=-1;
    dfs(1,0);
    k=dis[n]-1;
    cur=n,cnt=0,par=parent[par];
    while(1){
        if(cnt>=k-ceil(k/2.0) || par==1) break;
        cur=parent[cur];
        cnt++;
    }
    dfs1(cur,par);//
    if(num>n-num) cout<<"Snuke"<<endl;
    else cout<<"Fennec"<<endl;
    system("pause");
    return 0;
}