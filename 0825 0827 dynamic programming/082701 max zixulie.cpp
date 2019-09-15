
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
#define N 1002
void st(int ,int);
void ed(int ,int);
int a[N],dp[N];
int main(){
    ios::sync_with_stdio(false);

    int i,n,k,m;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0]=1;
    for(i=1;i<n;i++){
        m=0;
        for(k=0;k<i;k++){
            if(a[i]>=a[k]&&dp[k]>m)
                m=dp[k];
        }        
        dp[i]=m+1;
    }
    m=dp[0];
    for(i=1;i<n;i++){
        if(m<dp[i]) m=dp[i];
    }
    cout<<m<<endl;
    m=1;
    for(i=0;i<n;i++){
        if(dp[i]==m)
            cout<<a[i]<<' ';
        m++;
    }//错误的一个输出方法
    
    system("pause");
    return 0;
}