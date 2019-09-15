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
#define N 1005
int t,i,k,dp[N];
struct node
{
    int l,w,h;
    bool operator < (const node &n1){
        if(l==n1.l){
            return w>n1.w;
        }
        return l>n1.l;
    }
}cub[N*6];

int i,n,l,h,w;


int main(){
    
    while(scanf("%d",&n)&&n){
        //
        for(i=0;i<n;i++){
            cin>>l>>w>>h;
            cub[i*6].l=l;
            cub[i*6].w=w;
            cub[i*6].h=h;
            cub[i*6+1].l=w;
            cub[i*6+1].w=l;
            cub[i*6+1].h=h;
            ////////笨方法,还剩四个
        }
        sort(cub,cub+n);
        dp[0]=cub[0].h;
        for(i=1;i<n;i++){
            //m=0;
            for(j=0;j<i;j++){
                if(cub[i].l<cub[j].l &&cub[i].w<cub[j].w){
                    if(dp[i]>max_i){
                        max_i=dp[j];
                    }
                }
            }
            dp[i] = max_i+cub[i].h;
        }
        max_i=0;
        for(i=0;i<n;i++){
            if(dp[i]>max_i){
                max_i=dp[i];
            }
        }
        cout<<max_i<<endl;
    }
    system("pause");
    return 0;
}