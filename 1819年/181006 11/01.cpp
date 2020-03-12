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

struct node{
    int legal;
    int value_A;
    int value_B;
    int value_C;
    int total;
}fps[33];
int a[31],dp[31];
int n,m,i,j,k,value;
double val,q;
char typ;
int main(){
    while(scanf("%lf%d",&q,&n)==2&&n){
        memset(fps,0,sizeof(fps));
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        k=0;q=q*100;
        //
        for(i=0;i<n;i++){
            scanf("%d",&m);
            //cin.get();
            for(j=0;j<m;j++){
                scanf(" %c:%lf",&typ,&val);
                value=(int)(val*100);
                if(typ=='A'){
                    fps[i].value_A+=value;
                }else if(typ=='B'){
                    fps[i].value_B+=value;
                }else if(typ=='C'){
                    fps[i].value_C+=value;
                }else fps[i].legal=1;
            }
            if(fps[i].value_A>60000||fps[i].value_B>60000||fps[i].value_C>60000||
                fps[i].value_A+fps[i].value_B+fps[i].value_C>100000){
                    fps[i].legal=1;
                }
            fps[i].total=fps[i].value_A+fps[i].value_B+fps[i].value_C;
        }
        // for(i=0;i<n;i++){
        //     cout<<fps[i].legal<<" "<<fps[i].value_A<<" "<<fps[i].value_B<<" "<<fps[i].value_C<<endl;
        // }
        for(i=0;i<n;i++){
            if(fps[i].legal) continue;
            else {
                a[k++]=fps[i].total;
            }
        }
        sort(a,a+k,greater<int>());
        // for(i=0;i<k;i++){
        //     cout<<a[i]<<endl;
        // }
        for(i=0;i<k;i++){
            if(dp[k-1]==q) break;
            if(a[i]>q) continue;
            else if(a[i]==q){
                dp[k-1]=q;
                break;
            }
            if(i){
                dp[i]=dp[i-1];
            }
            if(!i){
                dp[i]=a[i];
            }else if(dp[i-1]+a[i]==q){
                dp[k-1]=q;
                break;
            }else if(dp[i-1]+a[i]<q){
                dp[i]=dp[i-1]+a[i];
            }else {
                for(j=0;j<i;j++){
                    if(dp[i-1]-a[j]+a[i]==q){
                        dp[k-1]=q;
                        break;
                    }
                    if(dp[i-1]-a[j]+a[i]<q)
                        dp[i]=max(dp[i],dp[i-1]-a[j]+a[i]);
                }
            }
        }
        printf("%.2lf\n",(double)dp[k-1]/100.0);
    }
    

    system("pause");
    return 0;
}