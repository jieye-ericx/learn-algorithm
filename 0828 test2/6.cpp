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
int t,n,di,i,sum,bi;
long long ri,le;
int a[1000004];

void dfs(int k,int dep){
    if(dep>=k) {
        if(bi>=le&&bi<=ri){
            sum++;
            bi=0;
        }
    
    }

}

int main(){
    
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld%lld%d",&n,&le,&ri,&di);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            dfs(i,0);
        }
        
    }
    system("pause");
    return 0;
}