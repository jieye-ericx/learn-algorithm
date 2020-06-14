//关于矩阵斐波那契数列
//
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


#define MOD 100000000
struct matrix{
	long long int a11,a12,a21,a22;
	void print(){
		cout<<a11<<'\t'<<a12<<endl<<a21<<'\t'<<a22<<endl;
	}
};

matrix mulM(matrix m1,matrix m2){
	matrix ret;
	ret.a11=(m1.a11*m2.a11%MOD+m1.a12*m2.a21%MOD)%MOD;
	ret.a12=(m1.a11*m2.a12%MOD+m1.a12*m2.a22%MOD)%MOD;
	ret.a21=(m1.a21*m2.a11%MOD+m1.a22*m2.a21%MOD)%MOD;
	ret.a22=(m1.a21*m2.a12%MOD+m1.a22*m2.a22%MOD)%MOD;

	return ret;
}

matrix powM(matrix & m,int n){
	if(n==1) return m;
	matrix tmp;
	tmp=powM(m,n>>1);
	if(n&1){
		return mulM(m,mulM(tmp,tmp));
	}else{
		return mulM(tmp,tmp);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	matrix m={1,1,1,0};
	int n;
	sd1(n);
	matrix ret=powM(m,n);
	cout<<(ret.a11+ret.a12)%MOD//斐波那契数列;

	
	return 0;
}


