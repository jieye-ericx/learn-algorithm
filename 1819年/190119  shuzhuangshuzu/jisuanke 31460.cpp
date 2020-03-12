#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define N 100005

int c[N];
int lowbit(int x){
	return x&(-x);
}
int getsum(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
int add(int i,int j){
	while(i<=N){
		c[i]+=j;
		i+=lowbit(i);
	}
}
int n,q,a,i,j,kl,b,c;
int main(){
	//ios::sync_with_stdio(false);
	while(scanf("%d%d",&n,&q)){
        for(i=1;i<=n;i++){
            scanf("%d",&kl);   
            add(i,kl);
        }
        while(q--){
            scanf("%d%d%d",&a,&b,&c);
            if(a==1){

            }else{
                
            }

        }
    }
	
	return 0;
}


