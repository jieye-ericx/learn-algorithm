/*
#include <iostream>
#include <cmath>
using namespace std;
int n,v;
int main(){
    int i,j;
    cin>>n>>v;
    for(i=0;i<n;i++){
        cin>>c[i]>>w[i];
    }
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++){
        for(j=1;j<=v;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
        }
    }

    //--------------------------------
    int now=v;
    for(i=n-1;i>=0;i--){
        if(dp[i][now]!=dp[i-1][now]){
            cout<<i+1<<' ';
            now-=c[i];
        }
    }
    if(dp[0][now]>0){
        cout<<1<<endl;
    }
}
*/
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
#define INF 0x3f3f3f3f
int n,v,i,j,k;
int c[1000],w[1000];
int dp[1000][1000];
int main(){
    
    
    //此为背包装满的最优解
    memset(c,0,sizeof(c));
    memset(w,0,sizeof(w));
    cin>>n>>v;
    for(i=1;i<=v;i++){
        dp[i]=0;
    }
    for(i=0;i<n;i++){
        cin>>c[i]>>w[i];
    }
    
    for(i=0;i<n;i++){
        for(j=v;j>=0;j--){
            dp[i][j]=dp[i][j-1];
            for(k=1;k<;k++){
                if(i-k*c[i]>=0&&dp[i][j]<dp[i-k*c[i]])
            }
        }
    }
    cout<<f[v]<<endl;

/*
10 5
2 6
2 3
6 5
5 4
4 6
*/
    system("pause");
    return 0;
    //--------------------------------
    
}