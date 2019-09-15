#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
using namespace std;
#define N 6000
int dp[N];

int min1(int x1,int x2,int x3,int x4,int x5){
    int ret=min(min(x1,x2),min(x3,x4));
    if(x1==ret) i++;
    if(x2==ret) j++;
    if(x3==ret) k++;
    if(x4==ret) m++;

    return ret;
}

int main(){
    dp[1]=1;
    int n,n1,i=1,j=1,k=1,m=1,in[4],size;
    cin>>n;
    priority_queue<pair<int,int>>;
    for(n1=2;n1<=n;n1++){
        dp[n1]=min1(2*dp[i],3*dp[j],5*dp[k],7*dp[m],in,size);
    }

    system("pause");
    return 0;
}