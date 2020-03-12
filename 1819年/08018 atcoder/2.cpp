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

int n,cnt,cnt1,i,j;int a[205]={0};
int main(){
	//ios::sync_with_stdio(false);
	for(i=1;i<203;i+=2){
		cnt=0;
		for(j=1;j<=i;j++){
			if(i%j==0){
				cnt++;
			}
		}
		if(cnt==8){
			cnt1++;
		}
		a[i]=cnt1;
		a[i+1]=cnt1;
	}
	while(sd1(n)!=EOF){
		pd1(a[n]);
	}
	return 0;
}


