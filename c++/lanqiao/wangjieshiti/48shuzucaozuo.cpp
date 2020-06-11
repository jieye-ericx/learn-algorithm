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
#define N 50005
int a,i,j,Case,n,m,x,y,k=1;
char ty[10];
int c[N];
int lowbit(int x){
	return x&(-x);
}
void add(int i,int val){
	while(i<=n){
		c[i]+=val;
		i+=lowbit(i);
	}
}
int getSum(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
int main(){
	scanf("%d",&Case);
	while(Case--){
		memset(c,0,sizeof(c));
		//
		printf("Case %d:\n",k++);
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			add(i,a);
		}
		while(1){
			scanf("%s",ty);
			if(!strcmp(ty,"Add")){
				scanf("%d%d",&x,&y);
				add(x,y);
			}else if(!strcmp(ty,"Sub")){
				scanf("%d%d",&x,&y);
				add(x,-y);
			}else if(!strcmp(ty,"Query")){
				scanf("%d%d",&x,&y);
				printf("%d\n",getSum(y)-getSum(x-1));
			}else break;
		}
	}
	
	return 0;
}


