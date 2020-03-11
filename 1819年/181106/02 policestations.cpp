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
#include <queue>
using namespace std;
#define N 300005
vector<pair<int,int>>g[N];
int n,k,d,vis[N];
int i,to,from,cur,now,ei,vis_e[N],tot=0,del[N];
int main(){
    queue<int>qu;
    cin>>n>>k>>d;
    for(i=0;i<k;i++){
        cin>>to;
        qu.push(to);
        vis[to]=1;
    }
    for(i=1;i<n;i++){
        cin>>to>>from;
        g[to].push_back(make_pair(from,i));
        g[from].push_back(make_pair(to,i));
    }
    pair<int,int> tmp;
    while(!qu.empty()){
        cur=qu.front();
        qu.pop();
        for(i=0;i<g[cur].size();i++){
            tmp=g[cur][i];
            now=tmp.first;
            ei=tmp.second;//cur=now的编号
            
            if(vis[now]) {
                if(!vis_e[ei]){
                del[tot++]=ei;
                }
                continue;
            }
            vis[now]=1;
            vis_e[ei]=1;
            qu.push(now);
        }
    }
    cout<<tot;
    for(i=0;i<tot;i++){
        cout<<del[i]<<' ';
    }cout<<endl;
    system("pause");
    return 0;
}