#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set> 
using namespace std;
#define N 5002

struct card{
	int l;
	int w;
	bool isv;
}Ali[N];

bool cmp(card & a,card &b){
	if(a.l!=b.l)
	return a.l<b.l;
	else return a.w<b.w;
}
int main(){
	ios::sync_with_stdio(false);
	int t,i,j,n,ll,ww,sum,flag;
	//cin>>t;
	scanf("%d",&t);
	while(t--){
		sum=1;
		memset(Ali,0,sizeof(card)*N);
		
		//////////////////
		
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&Ali[i].l,&Ali[i].w);
			Ali[i].isv=false;
		}	
		
		sort(Ali,Ali+n,cmp);
		for(i=0;i<n;i++){
			flag=1;
			if(Ali[i].isv==true) continue;
			ww=Ali[i].w;ll=Ali[i].l;
			
			for(j=i+1;j<n;j++){
				if(Ali[j].isv==true) continue;
				else if(Ali[j].l>=ll && Ali[j].w>=ww){
					ww=Ali[j].w;ll=Ali[j].l; 
					Ali[j].isv=true;
				}else {
					if(flag) {
						sum++;flag=0;
					}
				}
				
			}
		}
	
		printf("%d\n",sum);
	}
	return 0;
}


