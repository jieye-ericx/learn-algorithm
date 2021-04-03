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
#define N 1000066
int n,i,j;
int a[N],c[N];
long long b[N],su;
int lowbit(int x){
    return x&(-x);
}
long long getsum(int x){
	long long sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
void add(int x,int val){
	while(x<=n+1){
		c[x]+=val;
		x+=lowbit(x);
	}
}
int main(){
	//ios::sync_with_stdio(false);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));

	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		//zuo
		add(a[i]+1,1);
		b[i]=i-getsum(a[i]+1);
	}
	memset(c,0,sizeof(c));
	for(i=n;i>=1;i--){
		add(a[i]+1,1);
		b[i]+=getsum(a[i]);
	}
	su=0;
	for(i=1;i<=n;i++){
		su+=(1+b[i])*b[i]/2;
	}
	printf("%lld\n",su);
	return 0;
}


