#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int i,x,y;
int main(){
    cin>>n>>m;
    for(i=0;i<=n;i++){
        dp[i][1]=i;
    }
    for(y=2;y<=m;y++){
        for(x=1;x<=n;x++){
            dp[x][y]=dp[x-1][y]+1;
            for(k=1;k<=x;k++){
                dp[x][y]=min(dp[x][y],max(1+dp[x-1][y-1],1+dp[x-1][y]));
            }
        }
    }
    cout<<dp[n][m]<<endl;
    system("pause");
	return 0;
}
