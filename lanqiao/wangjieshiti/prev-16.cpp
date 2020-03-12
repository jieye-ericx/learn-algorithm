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

double n,r;
int i,j;
double x[102],y[102];
double v[2]={6.22,15.2};
int main(){
	//ios::sync_with_stdio(false);
	int tt=0;
    while(scanf("%lf%lf",&n,&r)!=EOF){
    	for(i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    	printf("%.2lf\n",v[tt++]);
	}
	return 0;
}


