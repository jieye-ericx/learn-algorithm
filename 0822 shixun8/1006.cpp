#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
//#include <windows.h>
using namespace std;
#define N 1005
int x[N],a[N],b[N],v[N],W;
int i;
int t,j,n,k,value,va,we;

bool canPut(int i){
    if(we+b[i]>W) return false;
    return true;
}

void dfs(int dep,int st){
    int i,j;
    if(dep>k){
        if(va>value) value=va;
        return; 
    }
    for(i=st;i<=n;i++){
        if(!v[i]&&canPut(i)){//i列dep行
            x[dep]=i;
            v[i]=1;
            va+=a[i];
            we+=b[i];
            dfs(dep+1,i+1);
            v[i]=0;
            we-=b[i];
            va-=a[i];
        }
    }
}


int main(){
    //ios::sync_with_stdio(false);
    scanf("%d",&t);
    while(t--){
        value=0;va=0;we=0;
        memset(v,0,sizeof(v));
        
        ///////////////
        scanf("%d%d",&n,&k);
        for(j=1;j<=n;j++){
            scanf("%d%d",&a[j],&b[j]);
        }scanf("%d",&W);
        ////////////
        dfs(1,0);
        printf("%d\n",value);
    }
    //system("pause");
    return 0;
}