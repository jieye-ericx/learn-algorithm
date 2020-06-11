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

int n,k,t,i,j;
long long sum,cnt,m;
int main(){
	//ios::sync_with_stdio(false);
	sd3(n,k,t);
	cnt=-n;
	m=1;sum=1;
	long long mm=(n+1)*n/2%k;
	for(i=0;i<t-1;i++){
		cnt=(cnt+n)%k;
//		sum+=((n*cnt)%k+(n+1)*n/2)%k;
		m=(m%k+cnt*n%k+mm)%k;
		sum+=m;
	}
	cout<<sum<<endl;
	return 0;
}


