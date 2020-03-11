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

int n,i,k=1;
int dp[3016];
struct tra{
long long x,y,z;
}tras[1005];
long long xi,yi,zi;

bool tmp(tra t1,tra t2){
    if(t1.x!)
}
int main(){
    while(~scanf("%d",&n)&&n){
        printf("Case %d: ",k);
        k++;
        memset(dp,0,sizeof(dp));
        memset(tras,0,sizeof(tras));
        
        //
        for(i=0;i<3*n;i++){
            scanf("%lld%lld%lld",&xi,&yi,&zi);
            tras[i].x=xi;tras[i].y=yi;tras[i].z=zi;
            i++;
            tras[i].x=yi;tras[i].y=zi;tras[i].z=xi;
            i++;
            tras[i].x=xi;tras[i].y=zi;tras[i].z=yi;
        }
        sort(tras,tras+3*n,tmp);
    }

    system("pause");
    return 0;
}