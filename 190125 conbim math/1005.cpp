#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1003
#define mod 1000000007
long long int dp[N][N];
// long long c[1005][1005];
int n,m,i,j,t;
// void init()
// {
//     memset(c,0,sizeof(c));
//     c[0][0]=c[1][0]=c[1][1]=1;
//     for(int i=2;i<=1005;i++)
//     {
//         c[i][0]=c[i][i]=1;
//         for(int j=1;j<i;j++)
//         c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
//     }
// }
int main(){
        // init();
        for(i=1;i<=N;i++){
            dp[i][i]=1;
            dp[1][i]=i;
        }
        for(i=2;i<=N;i++){
            for(j=i+1;j<=N;j++){
                dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
            }
        }
        // for(i=1;i<=N;i++){
        //     for(j=i;j<=N;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("%lld\n",dp[min(n,m)][max(m,n)]);        
        //printf("%lld\n",dp[max(n,m)][min(m,n)]);
        // printf("%lld\n",c[max(m,n)][min(n,m)]);


	}
    system("pause");
	return 0;
}
