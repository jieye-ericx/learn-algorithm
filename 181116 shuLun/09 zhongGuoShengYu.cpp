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

long long inv(int a,int n){
    return a==1?1:(m-m/a)*inv(m%a)%m;
}

long long chinaRem(int b[],int m[],int n){
    long long ret,M=1,M1;
    int i;
    for(i=0;i<n;i++){
        M*=m[i];
    }
    for(i=0;i<n;i++){
        M1=M/m[i];
        ret=(ret+b[i]*M1*inv(M1,m[i])%M+M)%M;
    }
    return ret;
}

int  main(){
int b[]={2,3,7};

    return 0;
}