
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
long long k;
#define mod 998244353
struct matrix{
	long long a11,a12,a21,a22;
};

matrix mul(matrix m1,matrix m2){
	matrix a;
	a.a11=((m1.a11%mod*m2.a11%mod)%mod+(m1.a12%mod*m2.a21%mod)%mod)%mod;
	a.a12=((m1.a11%mod*m2.a12%mod)%mod+(m1.a12%mod*m2.a22%mod)%mod)%mod;
	a.a21=((m1.a21%mod*m2.a11%mod)%mod+(m1.a22%mod*m2.a21%mod)%mod)%mod;
	a.a22=((m1.a21%mod*m2.a12%mod)%mod+(m1.a22%mod*m2.a22%mod)%mod)%mod;
	return a;
}

matrix mi(matrix m1,long long n){
	if(n==1) return m1;
	matrix tmp=mi(m1,n>>1);
	
	if(n&1) return mul(mul(tmp,tmp),m1);
	else return mul(tmp,tmp);
}
matrix mm={1,1,1,0},mp;

int main(){
	//ios::sync_with_stdio(false);
	
	while(sd1(k)!=EOF){
		
		matrix mp=mi(mm,2*k+2);
		printf("%lld\n",mp.a11-1);
		
		
	}
	return 0;
}


