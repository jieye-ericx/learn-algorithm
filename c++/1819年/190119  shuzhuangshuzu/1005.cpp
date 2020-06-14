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
#define N 1000000005
int c[N];
int i,j,n,m,k;
long long int s,t;

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
int add(long long int i,long long int j){
	while(i<=N){
		c[i]+=j;
		i+=lowbit(i);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		printf("Case #%d:\n",k);
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			scanf("%lld%lld",&s,&t);
			s/=1000;
			
			add(s,1);
			add(t+1,-1);
			//todo
		}
		for(i=0;i<m;i++){
			scanf("%d",&t);
			printf("%d",getsum(t));
			//todo
		}
	}
	return 0;
}


