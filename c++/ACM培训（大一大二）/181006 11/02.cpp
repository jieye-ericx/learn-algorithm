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

int n,m,s,k,a,b,i,j,p;//n还需要的经验值m保留的忍耐度k怪的总数s最多杀怪数
int dp[102][102];
struct node
{
    int aa,bb;
}as[101];
bool tmp(node n1,node n2){
    return n1.aa*n2.bb>n1.bb*n2.aa;
}

int main(){
    while(cin>>n>>m>>k>>s){
        // cin>>k;
        for(i=0;i<101;i++){
            as[i].aa=0;as[i].bb=0;
        }
        memset(dp,0,sizeof(dp));
        //
        for(i=0;i<k;i++){
            scanf("%d%d",&as[i].aa,&as[i].bb);
        }
        sort(as,as+k,tmp);//排序不一定是必须需要的
        // for(i=0;i<k;i++){
        //     cout<<as[i].aa<<" "<<as[i].bb<<endl;
        // }
        for(i=0;i<k;i++){
            if(as[i].bb>m) continue;
            for(j=1;j<=s;j++){
                for(p=as[i].bb;p<=m;p++){
                    dp[p][j]=max(dp[p][j],dp[p-as[i].bb][j-1]+as[i].aa);
                }
            }
        }
        if(dp[m][s]<n)cout<<"-1"<<endl;
        else{
            for(i = 0; i <= m; ++i){
                if(dp[i][s] >= n){
                    cout << m-i << endl;
                    break;
                }
            }
        }
    }
    

    system("pause");
    return 0;
}