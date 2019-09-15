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
#define mod 1000000009
#define K 100004
int s[K];

long long inv(long long a,int m){
    while(a<0) a+=m;
    a%=m;
    return a==1?1:(m-m/a)*inv(m%a,m)%m;
}

long long qpow(long a,long long n){
    if(n==0) return 1;
    long long d=qpow(a,n>>1);
    if(n&1){
        return a*(d%mod)*(d%mod);
    }else{
        return (d%mod)*(d&mod);
    }
}


int main(){
    long long n,i,j,a,b,k,a1;
    char ch;
    cin>>n>>a>>b>>k;
    for(i=0;i<k;i++){
        cin>>ch;
        if(ch=='+'){
            s[i]=1;
        }else s[i]=-1;
    }
    for(i=0;i<k;i++){
        a1=(a1+s[i]*qpow(a,n-i)%mod*qpow(b,i)%mod+mod)%mod;
    }
    int n1=(n+1)/k;
    long long q=qpow(b,k)%mod*qpow(inv(a,mod),k)%mod;
    if(q==1){
        cout<<n1*a1%mod<<endl;
        return 0;
    }
    long long ret;
    ret=a1*(qpow(q,n1)-1)%mod *inv(q-1,mod)%mod;

    system("pause");
    return 0;
}