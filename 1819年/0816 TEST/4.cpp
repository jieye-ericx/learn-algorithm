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

int n,i,j,sum;long long a[100005],t;
int main(){
	//ios::sync_with_stdio(false);
	sd1(t);
	while(t--){
		sd1(n);sum=0;
		for(i=0;i<n;i++) slld1(a[i]);
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				t=a[i]+a[j];
				if((t&t-1)==0){
					sum++;

				}
			}
		}
		pd1(sum);
	}
	return 0;
}


