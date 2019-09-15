//原排列
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
int n=6,k=3,num=1;
char a[]={'a','b','c','d','e','f'},x[N];
int vis[N];//xis[i]=0表示第i元素未使用过

void dfs(int st,int dep){
    int i;
    if(dep>=k){
        cout<<num++<<" ";
        for(i=0;i<k;i++){
            cout<<x[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(i=st+1;i<n;i++){
        if(!vis[i]){
        x[dep]=a[i];
        vis[i]=1;
        dfs(st,dep+1);
        vis[i]=0;
        }
        
    }
}
/*
    void dfs(int dep){
    int i;
    if(dep>=n){
        for(i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(i=dep;i<n;i++){
        swap(a[dep],a[i]);
        dfs(dep+1);
        swap(a[dep],a[i]);
        }
        
    }
}
*/
int i;
int main(){
    ios::sync_with_stdio(false);
    for(i=0;i<n-k+1;i++){
        x[0]=a[i];
        dfs(i,1);
    }
    
    system("pause");
    return 0;
}