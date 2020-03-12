/*
 D(4)=D(3)+4*2-1+3+2+1+1
 D(5)=D(4)+5*2-1+4+3+2+1+2+0
 D(6)=D(5)+6*2-1+5+4+3+2+1+3+1
 n为偶数时D(n)=D(n-1)+n*2-1+(n-1)+(n-2)+…+1+(n-3)+(n-5)+..+1
 n为奇数时D(n)=D(n-1)+n*2-1+(n-1)+(n-2)+…+1+(n-3)+(n-5)+..+0
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int f[505];

int main(){
	ios::sync_with_stdio(false);
	
	int n,i;
	for( i=1; i<501 ;i++){
		if(i%2==1)f[i]=f[i-1]+2*i-1+i*(i-1)/2+(i-3)*(i-1)/4;
		else f[i]=f[i-1]+2*i-1+i*(i-1)/2+(i-2)*(i-2)/4;
	}
	while(~scanf("%d",&n)){
		printf("%d\n",f[n]);
	}
	 
	return 0;
}


