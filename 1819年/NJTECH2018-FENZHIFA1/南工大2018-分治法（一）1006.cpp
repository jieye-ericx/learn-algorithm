#include <iostream>
#include <cstring>
#include <string>

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

long long x,m,mod,k,c,p,z;
int t,i,j;

long long mi(long long x,long long y){

    long long tmp=1;
    while(x){
        if(x&1){
            tmp=tmp*y%mod;
        }
        y=y*y%mod;
        x>>=1;

    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(false);

    scanf("%d",&t);
    for(j=0;j<t;j++){

        scanf("%d%lld%d%d",&x,&m,&k,&c);
        mod=9*k;
        p=mi(m,10);
        z=(p-1)*x%mod;

        printf("Case #%d:\n",j+1);
        if(z==9*c)printf("Yes\n");
        else printf("No\n");
        //if(j!=t-1) printf("\n");
    }
    return 0;
}

