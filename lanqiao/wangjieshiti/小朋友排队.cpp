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
#define N 1000004
int n,i,j;
int a[N],b[N],c[N];
int lowbit(int x){
    return x&(-x);
}
int getsum(int x){
	int sum=0;
	while(x>=0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
void add(int x,int val){
	while(x<=n){
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
	for(i=0;i<=8;i++){
		//scanf("%d",&a[i]);
		add(i,1);
		cout<<getsum(i)<<endl;
	}
	return 0;
}


