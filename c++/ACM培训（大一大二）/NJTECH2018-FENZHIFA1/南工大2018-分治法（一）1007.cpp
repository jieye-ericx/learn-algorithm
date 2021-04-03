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
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define p(a) printf("%d\n",a)
#define N 200000005
int i,j,k,n;
long long a[N];

int main(){
	//ios::sync_with_stdio(false);
	sd1(k);
	while(k--){
		sd1(n);
		for(i=i;i<N;i++){
			a[i]=((1+i)*i)>>1;
			p(a[i]);
		}
		
	}
	return 0;
}


