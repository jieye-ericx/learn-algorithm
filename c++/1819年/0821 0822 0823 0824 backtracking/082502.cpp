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

struct node{
    int lx,rx,w,h;
    bool operator < (const node & n1) const{
        return h<n1.h;
    }
}layer[1002];

int down(int x,int st){
    int j;
    for(j=st;j>=0;j--){
            if(lx<layer[j].rx&&lx>layer[j].lx){
                return j;
            }
        }
}

int n,MAX,dp[1002][2];
int main(){
    int i,j,sx,sy,lx,rx,dl,dr;
    cin>>n>>sx>>sy>>MAX;
    layer[0].lx=layer[0].rx=sx;
    layer[0].h=sy;
    for(i=1;i<=n;i++){
        cin>>layer[i].lx>>layer[i].rx>>layer[i].h;
    }
    sort(layer,layer+n+1);
    for(i=0;i<=n;i++){
        lx=layer[i].lx,rx=layer[i].rx;
        dl=down(lx,i-1);
        dr=down(rx,i-1);
        dp[i][0]=min(dp[dl][0]+lx-layer[dl].lx,
                    dp[dl][1]-lx+layer[dl].rx);
        dp[i][1]=min(dp[dr][0]+rx-layer[dr].lx,
                    dp[dr][1]-rx+layer[dr].rx);
        
    }
    cout<<dp[n][0]+sy<<endl;
    system("pause");
    return 0;
}