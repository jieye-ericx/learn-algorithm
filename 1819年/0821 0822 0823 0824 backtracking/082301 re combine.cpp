#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
#include<Windows.h>
#include<map>
using namespace std;
#define N 7
int x[N],n,k,ans=0,sum=0;
void dfs(int st,int dep){
    int i;
    if(dep>=k-1){
        sum=0;
        for(i=0;i<k-1;i++){
            sum+=x[i];
        }
        if(n-sum>=x[k-2]){
            ans++;
        }
        return;
    }
    for(i=st;i<=n;i++){
        if(n-sum<i*(k-dep))
            break;
        else{
            x[dep]=i;
            sum+=i;
            dfs(i,dep+1);
            sum-=i;
        }
        
    }
}

int main(){
    cin>>n>>k;
    dfs(1,0);
    cout<<ans<<endl;
    system("pause");
    return 0;
}