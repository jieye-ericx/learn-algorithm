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
long long n,max1,max2;
long long f[100002];

long long comp(long long x){
    while(x!=1){
        if(x>max1) max1=x;
        if(x&1){
            x=3*x+1;
        }else{
            x/=2;
        }
        
    }
    return max1;
}
int main(){
    long long i;
    //max1=0;
    for(i=1;i<100002;i++){
        max1=0;
        f[i]=comp(i);
    }
    while(scanf("%lld",&n)!=EOF){
        max2=0;
        for(i=1;i<=n;i++){
            if(f[i]>max2) max2=f[i];
        }
        if(f[i]>max2) max2=f[i];
        
        printf("%lld\n",max2);
    }
    //system("pause");
    return 0;
}
//------------------
