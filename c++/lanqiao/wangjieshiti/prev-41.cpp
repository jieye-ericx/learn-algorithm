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

long long a,pow1[100];
int cnt1,cnt2,t,i,j,flag;
char b[100000],c;
char to[27];
int main(){
	//ios::sync_with_stdio(false);
	for(i=0;i<13;i++) {
		pow1[i]=pow(26,i);
		//cout<<pow1[i]<<" ";
	}
	cnt1=0;
	cnt2=0;
	to[0]='0';
	for(i=1;i<=26;i++) to[i]=i-1+'A';
//	cout<<to;
	scanf("%lld",&a);
	
	while(a>0){
		for(j=12;j>=0;j--){
			if(flag) break;
			if(a>=pow1[j]){
				for(i=1;i<=26;i++){
					if(i*pow1[j]>a) {
						b[cnt1++]=to[i-1];
						a-=(i-1)*pow1[j];
						if(a==0) {
							flag=1;
							break;
						}
						if(a<26*pow1[j-1]){
							a+=pow1[j];
							if(i-2==0) cnt1--;
							else
							b[cnt1-1]=to[i-2];
						}
					}
					if(flag) break;
				}
				if(flag) break;
			}
		}
		
	}
//	for(i=cnt1-1;i>=0;i--)
	//printf("%c",b);
	cout<<b;
	printf("\n");
	return 0;
}


