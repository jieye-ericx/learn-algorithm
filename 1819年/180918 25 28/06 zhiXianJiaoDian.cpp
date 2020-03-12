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

#define N 22
int dp[N][N*(N-1)*2];
int main(){
    int n,i,r,j;
    for(i=0;i<=n;i++){
        dp[i][0]=1;
    }
    while(cin>>n){
        for(i=0;i<=n;i++){
            for(r=0;r<=i;r++){//与新加直线平行的直线数量为i-r
                for(j=0;j<=r*(r-1)/2;j++){//判别r条直线的所有可能交点的情况
                    if(dp[r][j]==1){
                        dp[i][(i-r)*r+j]=1;
                    }
                }
            }
        }
        for(i=0;i<=n*(n-1)/2;i++){
            if(dp[n][i]) cout<<i<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}