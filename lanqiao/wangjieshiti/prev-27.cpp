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

int i,j,k,n,gx,gdis,x,dis,cnt=1;
int main(){
	//ios::sync_with_stdio(false);
	scanf("%d",&n);
	scanf("%d",&gx);
	if(gx>0) gdis=1;
	else gdis=-1;
	gx=abs(gx);
	for(i=1;i<n;i++){
		scanf("%d",&x);
		if(x>0) dis=1;
		else dis=-1;
		x=abs(x);
		
		if(gdis<0){
			if( (x<gx&&dis!=gdis)||(x>gx&&dis==gdis) ) cnt++;
		}else if( (x<gx&&dis==gdis)||(x>gx&&dis!=gdis) ) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}


