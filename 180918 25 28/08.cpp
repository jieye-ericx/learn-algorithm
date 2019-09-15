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
#define N 102
#define INF 0x3f3f3f3f
int dp[N][N];
int p[N];
int n,i,j,k,r;
int main(){
    cin>>n;
    for(i=1;i<=n+1;i++){
        cin>>p[i];
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            dp[i][j]=INF;
        }
    }
    for(r=2;r<=n;r++){
        for(i=1;i<=n;i++){
            j=i+r-1;
            if(j>n){
                break;
            }
            for(k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j]);
            }
        }
    }
    system("pause"); 
        return 0;
}