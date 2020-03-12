//部分全排列
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
#define M 1000003
int n=6,k=3,num=1,tot=0,sum=0;
int a[]={12,34,13,8,19,22},x[N];
int vis[N];//xis[i]=0表示第i元素未使用过

//埃氏筛法
void gprime(){
    int i,j;
    for(i=2;i<M;i++){
        if(!check[i]){
            prime[tot++]=i;
            for(j=2;j<M;j++){
                check[i*j]=1;
            }
        }
    }
}
//欧拉筛法
long long prime[M],check[M];
void olgprime(){
    int i,j;
    for(i=2;i<M;i++){
        if(!check[i]){
            prime[tot++]=i;
        }
        for(j=0;j<tot;j++){
            if(prime[j]*i>=M) break;
            check[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
        
    }
}
//随机测试法
long long qpow(long long a,long long n,long long p){//p为取模的数
    if(n==1) return a;
    long long temp=qpow(a,n>>1,p);
    if(n&1){
        return a*temp%p*temp%p;
    }else{
        return temp*temp%p;
    }

}

bool isPrime(int x){
    int i;long long a;
    for(i=0;i<4;i++){
        a=2+rand()%(x-2);
        if(qpow(a,x-1,x)!=1)
            return false;
    }
    return true;
}

void dfs(int st,int dep){
    int i;
    if(dep>=k){
        cout<<num++<<" ";
        for(i=0;i<k;i++){
            cout<<x[i]<<' ';
            sum+=x[i];
        }
        cout<<endl;
        return;
    }
    for(i=0;i<n;i++){
        if(!vis[i]){
        x[dep]=a[i];
        dfs(i+1,dep+1);
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

int main(){
    ios::sync_with_stdio(false);
    dfs(0,1);
    system("pause");
    return 0;
}