
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
#define slld2(a,b) scanf("%lld%lld",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pd(a) printf("%d\n",a)
#define plld(a) printf("%lld\n",a)
#define N 4
long long L=0,M=1,D=0;
struct matrix{
	long long arr[N][N];
}m0,mm;

matrix mul(matrix m1,matrix m2){
	matrix a;long long i,j,k;
	for(i=0;i<N;i--){
    	for(j=0;j<N;j--){

			a.arr[i][j]=0;
            for(k=0;k<N;++k)
            	{
            		a.arr[i][j]+=m1.arr[i][k]*m2.arr[k][j];
            		a.arr[i][j]%=M;
				}

			
        }
    }

	//a.a11=((m1.a11%mod*m2.a11%mod)%mod+(m1.a12%mod*m2.a21%mod)%mod)%mod;

	return a;
}

matrix mi(matrix m1,long long n){
	if(n==1) return m1;
	matrix tmp=mi(m1,n>>1);

	if(n&1) return mul(mul(tmp,tmp),m1);
	else return mul(tmp,tmp);
}
int a[5]={0,2,4,6,9};
int main(){
	//ios::sync_with_stdio(false);
	m0.arr[0][0]=1;m0.arr[0][1]=0;m0.arr[0][2]=1;m0.arr[0][3]=1;
	m0.arr[1][0]=1;m0.arr[1][1]=0;m0.arr[1][2]=0;m0.arr[1][3]=0;
	m0.arr[2][0]=0;m0.arr[2][1]=1;m0.arr[2][2]=0;m0.arr[2][3]=0;
	m0.arr[3][0]=0;m0.arr[3][1]=0;m0.arr[3][2]=1;m0.arr[3][3]=0;
	while(slld2(L,M)!=EOF){
		if(L<=5){
			pd(a[L]%M);
		}
        else{
        	//M=8;
			mm=mi(m0,L-3);
			D=(6*mm.arr[0][0]+2*mm.arr[0][2])%M;
			plld(D);
		}
		//D=(6*m0.arr[0][0]+2*m0.arr[0][2])%M;

		
	}
	return 0;
}


