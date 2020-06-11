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
#define N 100003
int a[N],dp[N];
int t,n,i,g,j,m,x,y;

int main(){
    scanf("%d",&t);
    for(g=1;g<=t;g++){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        //
        cout<<"Case "<<g<<":"<<endl;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dp[1]=1;
        for(j=2;j<=n;j++){
            if(a[j-1]>=0){
                a[j]=a[j-1]+a[j];
                dp[j]=dp[j-1];
            }else{
                dp[j]=j;
            }
        }
        m=a[1];x=y=1;
        for(j=1;j<=n;j++){
            if(a[j]>=m){
                m=a[j];
                y=j;
                x=dp[j];
            }
        }
        printf("%d %d %d\n",m,x,y);
        if(g!=t) printf("\n");
    }
    

    system("pause");
    return 0;
}