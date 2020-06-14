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

int a[102],b[102];
int flag,i,j,pre,n;
char c;
bool check(){
	int t,sum=0;
	for(t=0;t<i-1;t+=2){
		sum^=(a[t+1]-a[t]-1);
	}
	return sum<=0;
}
int main(){
	//ios::sync_with_stdio(false);
	i=0;
	flag=0;
	while(1){
		scanf("%d",&a[i]);
		scanf("%c",&c);
		b[i]=a[i];
		i++;
		if(c==10) break;
	}
	if(check()){
		printf("-1\n");
	}else{
		for(j=0;j<i-1;j++){
			pre=a[j];
			while(a[j]+1<a[j+1]){
				 a[j]++;
				if(check()){
					printf("%d %d",pre,a[j]);
					flag=1;
					break;
				}
			}
			if(flag) break;
			a[j]=b[j];
		}
	}
	return 0;
}


