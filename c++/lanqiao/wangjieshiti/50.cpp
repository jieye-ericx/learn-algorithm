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
#define N 100005
int n,k,i,j,t,cnt,ans,maxt;
int a[N],val[N],dp[N];
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(a,0,sizeof(a));
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        ans=0;
        //
        for(i=0;i<n;i++){
            scanf("%d",&t);
            a[t]++;
            maxt=max(t,maxt);
        }
        if(k == 0) {
            for(i = 0; i <= maxt; i++) {
                if(a[i]) ans++;
            }
        }else{
            for(i=0;i<k;i++){
                int m=0;
                for(j=i;j<=maxt;j+=k){
                    val[m++]=a[j];
                }
                dp[0]=val[0];
                dp[1]=max(val[1],val[0]);
                for(t=2;t<m;t++){
                    dp[t]=max(dp[t-1],dp[t-2]+val[t]);
                }
                ans+=dp[m-1];
            }
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
