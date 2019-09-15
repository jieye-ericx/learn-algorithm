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
struct node
{
    int index;
    int value;
};
node temp;
vector<node>g[N];
//vector<pair<int,int>>g1[N];
int n,dis[N];
int i,j,to,from,v;

void dfs(int cur,int par){
    int i,now,v;
    pair<int,int> p;
    
    for(i=0;i<g[cur].size();i++){
        p=g[cur][i];
        now=p.first;
        v=p.second;
        if(now==par) continue;
        dis[now]=dis[cur]+v;
        dfs(now,cur);//回退
    }
}

int main(){
    while(cin>>n){
        for(i=1;i<n;i++){
            cin>>to>>from>>v;
            temp.index=from;
            temp.value=v;
            g[to].push_back(temp);
            temp.index=to;
            g[from].push_back(temp);
            // //
            // temp=make_pair(from,v);
            // g1[to].push_back(temp);
            // g1[from].push_back(make_pair(to,v));
        }
    }
    
    system("pause");
    return 0;
}