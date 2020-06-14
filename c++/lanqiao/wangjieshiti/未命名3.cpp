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
#define sd1(a) scanf("%d",&a)
#define slld1(a) scanf("%lld",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pd1(a) printf("%d\n",a)
#define plld1(a) printf("%lld\n",a)
#define N 100
int a[N];
int ans;
struct node{
	int le,ri,val;
} tree[4*N+1];
void build(int l,int r,int k){
	tree[k].le=l;
	tree[k].ri=r;
	if(l==r){
		scanf("%d",&tree[k].val);
		return;
	}
	int mid=((tree[k].le+tree[k].ri)>>1);
	build(l,mid,2*k);
	build(mid+1,r,2*k+1);
	tree[k].val=tree[2*k].val+tree[2*k+1].val;
}
int ask(int k,int x){
	if(tree[k].le==tree[k].ri){
		ans=tree[k].val;
		return ans;
	}
	int mid=(tree[k].le+tree[k].ri)>>1;
	if(x<=mid){
		ask(2*k,x);
	}else{
		ask(2*k+1,x);
	}
}
void add(int k,int x,int y){
	if(tree[k].le==tree[k].ri){
		tree[k].val+=y;
		return;
	}
	int mid=(tree[k].le+tree[k].ri)>>1;
	if(x<=mid){
		add(2*k,x,y);
	}else{
		add(2*k+1,x,y);
	}
	tree[k].val=tree[2*k+1].val+tree[2*k].val;
}
void sum(int k,int x,int y){
	if(tree[k].le>=x&&tree[k].ri<=y){
		ans+=tree[k].val;
		return;
	}
	int m=(tree[k].le+tree[k].ri)>>1;
    if(x<=m) sum(k*2,x,y);
    if(y>m) sum(k*2+1,x,y);
}

int main(){
	//ios::sync_with_stdio(false);
	for(int i=1;i<=8;i++){
		a[i]=1;
	}
	build(1,8,1);
	sum(1,4,5);
	cout<<ans<<endl;
	ans=0;
	sum(1,1,5);
	cout<<ans<<endl;
	ans=0;
	sum(1,2,5);
	cout<<ans<<endl;
	ans=0;
	sum(1,3,7);
	cout<<ans<<endl;
	ans=0;
	add(1,4,1);
	cout<<ask(1,8)<<" "<<ask(1,4)<<endl;
	for(int k=1;k<=15;k++){
		cout<<tree[k].le<<" "<<tree[k].ri<<" "<<tree[k].val<<endl;
	}
	return 0;
}


