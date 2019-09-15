#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int rooms[403]={0};
int main(){
	ios::sync_with_stdio(false);
	int x,n,s,t,i,j,k,max;
	cin>>x;
	while(x--){
		
		/////////////
		max=0;
		for(i=0;i<403;i++){
			rooms[i]=0;
		}
		/////////////
		cin>>n;
		while(n--){
			cin>>s>>t;
			if(s>t){
				swap(s,t);
			}
			if(s%2){
				i=s+1;
			}else{
				i=s;
			}
			
			if(t%2){
				j=t+1;
			}else{
				j=t;
			}
			
			for(k=i;k<=j;k+=2){
				rooms[k]++;
			}
		}
		max=rooms[0];

		for(i=2;i<403;i+=2){
			if(rooms[i]>max) max=rooms[i];
		}
		printf("%d\n",10*max);
	}
	return 0;
}


