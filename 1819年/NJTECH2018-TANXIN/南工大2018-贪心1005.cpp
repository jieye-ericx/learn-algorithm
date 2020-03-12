#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int sodas[10002];
int main(){
	ios::sync_with_stdio(false);
	int i,j,n,sum;
	scanf("%d",&i);
	while(i--){
		sum=0;
		/////////
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			scanf("%d",&sodas[i]);
			sum+=sodas[i];
		}
		if(sum%n==0){
			
		}else{
			printf("NO");
		}
		
		if(i!=0) printf("\n");
	}
	
	return 0;
}


