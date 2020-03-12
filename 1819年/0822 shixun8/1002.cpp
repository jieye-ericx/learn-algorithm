#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
//#include<Windows.h>
#include<map>
using namespace std;
#define M 1000003

int check[M]={0};
int i,n,j,k=1;
int main(){
    for(i=2;i<M;i++){
        if(!check[i]){
            check[i]=k;

        	for(j=i+i;j<M;j+=i){
				check[j]=k;
        	}
        	k++;
    	}

    }
    while(~scanf("%d",&n)){
        printf("%d\n",check[n]);
	}
    return 0;
}
