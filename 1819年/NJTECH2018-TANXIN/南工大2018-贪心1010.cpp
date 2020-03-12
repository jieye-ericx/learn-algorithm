#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set> 
using namespace std;
#define N 22
multiset<int> pp;

struct node{
	int dps;
	int hp;
}enemys[N];

bool cmp(node & a,node & b){
	return a.dps*b.hp>b.dps*a.hp;
}


int main(){
	ios::sync_with_stdio(false);
	int t,n,i,j,sum,zdps;
	
	while(~scanf("%d",&t)){
		sum=0;zdps=0;
		////
		for(n=0;n<t;n++){
			scanf("%d%d",&enemys[n].dps,&enemys[n].hp);
		}
		sort(enemys,enemys+t,cmp);
		
		for(i=0;i<n;i++){
			zdps+=enemys[i].dps;
		}
		for(i=0;i<n;i++){
			sum+=zdps*enemys[i].hp;
			zdps-=enemys[i].dps;
		}
		printf("%d\n",sum);
		
	}

	return 0;
}


