#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long int t,n;
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int i;
void dfs(int cur,int pim,int fol){
    long long int num=(long long int)pow(n,1.0/pim);
    if(num>1){
        if(fol&1) t+=num-1;
        else t-=num-1;
    }
    if(fol>2) return;
    for(int i=cur+1;i<17;i++)
        dfs(i,pim*p[i],fol+1);
}
int main(){
    
    while(scanf("%lld",&n)!=EOF){//不加EOF会超时！！！
        t=1;
        for(i=0;i<17;i++)
            dfs(i,p[i],1);
        printf("%lld\n",t);
	}
    //system("pause");
	return 0;
}

