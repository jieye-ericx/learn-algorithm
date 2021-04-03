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
#define N 10005
int vis[N];
int main(){
    int n,m,k,cnt,c;
    cin>>n>>m;
    k=0;
    while(cnt==n-1){
        if(!vis[k]) continue;
        k=(k+1)%n;
        c++;
        if(c==n){
            vis[k]=1;
            c=1;
            cnt++;
        }
        
    }
    system("pause");
    return 0;
}