#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define mod 1000000007
long long t;

long long fm(int n){
    if(n<=0) return 1;
    if(n==1) return 3;
    if(n&1){
        return ((fm(n/2)%mod)*(fm(n/2)%mod)*3)%mod;
    }else{
        return ((fm(n/2)%mod)*(fm(n/2)%mod%mod));
    }
}
long long ans;
int main(){
    ios::sync_with_stdio(false);
    // for(int i=0;i<10;i++){
    cin>>t;
    ans=(4*fm(t-2))%mod;
    cout<<ans<<"\n";
    
    // }
    // system("pause");
    return 0;
}