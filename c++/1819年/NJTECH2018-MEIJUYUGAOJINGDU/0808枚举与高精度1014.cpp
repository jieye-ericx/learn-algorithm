#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define max 100000
int a[max]={0};

int main(){
	ios::sync_with_stdio(false);
	int n,i,j,len,c;
	while(cin>>n){
		
		memset(a,0,max*sizeof(int));
		a[0]=1;len=1;c=0;
		
		
		for(i=1;i<=n;i++){
			for(j=0;j<len;j++){
				
				a[j]=a[j]*i+c;
				if(a[j]>9){
					c=a[j]/10;
					a[j]%=10;
				}
				else {
					c=0;
				}
			}
			if(c){
				while(c>0){
					a[j]=c%10;
					c/=10;
					j++;
					len++;
				}
			}
		}
		for(i=len-1;i>=0;i--){
			cout<<a[i];
		}cout<<endl;
	} 
	return 0;
}


