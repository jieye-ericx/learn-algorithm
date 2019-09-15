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
#define mod 1000000007
long long inv(long long a,int m){
    while(a<0) a+=m;
    a%=m;
    return a==1?1:(m-m/a)*inv(m%a,m)%m;
}
//求组合c（吗，n）对mod取模
long long com(int m,int n){
    long long ret,i;
    for(i=m-1;i>=m-n+1;i--){
        ret=(ret*i)%mod;
    }
    for(i=2;i<=n;i++){
        ret=(ret*inv(i,mod))%mod;
    }
    return ret;
}

int main(){
    cout<<com(4,3);
    system("pause");
    return 0;
}