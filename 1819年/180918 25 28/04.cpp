
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
#define N 10000003
int n,v,i,j,k,x;

int dp[N],st[N];
int main(){
    cin>>n;
    dp[0]=0;
    for(i=1;i<=n;i++){
        cin>>x;
        if(dp[i-1]>0){
            dp[i]=dp[i-1]+x;
            st[i]=st[i-1];
        }else{
            dp[i]=x;
        }
    }
    int ans=0;
    int st1,ed1;
    for(i=1;i<=n;i++){
        if(ans<dp[i]){
            ans=dp[i];
            st1=st[i];
            ed1=i;
        }
    }
    cout<<ans<<st1<<" "<<ed1;
    //
    system("pause");
    return 0;
    //--------------------------------
    
}