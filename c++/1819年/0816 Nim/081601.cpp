//组合博弈入门
//巴士博弈 二人23张扑克牌 一次取1、2、3张，去最后一次的玩家获胜

//-----------------
//n张牌，一次取1，3，7张
/*
0 P
1 N
2 P
3 N
4 P
5 N
6 P
7 N
8 P
9 N
*/
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
#define N 1000003
int e[N]={0};
int main(){
	//ios::sync_with_stdio(false);
	e[0]=0;
	int i,a,b,c;
	cin>>a>>b>>c;
	for(i=1;i<N;i++){
		if(i>a&&e[i-a]==0) e[i]=1;
		else if(i>=b&&e[i-b]==0) e[i]=1;
		else if(i>=c&&e[i-c]==0) e[i]=1;
	    else e[i]=0;
	}
	int st=max(b,max(c,d));
	for(i=2*st;;i++){
		int i1=i;
		for(j=0;j<i-st&&i1<i-st;j++){
			int j1=j;
			while(1){
				if(a[i1++]!=a[j1++])
					break;
			}
		
		}
	}
	return 0;
}


