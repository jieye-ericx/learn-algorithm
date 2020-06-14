#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define LL long long
//返回a的n次方 
LL MOD=270;
LL powl(int a,int n){
	if(n==0) return 1;
	LL tmp=powl(a,n>>1);
	if(n&1){
		return a*tmp*tmp%MOD;
	}
	else
		return tmp*tmp%MOD;
}
int main(){
	ios::sync_with_stdio(false);
	cout<<powl(3,101)<<endl;
	return 0;
}


