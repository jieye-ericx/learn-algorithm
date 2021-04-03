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

int n,a,m,b,c;
double x;
int main(){
	//ios::sync_with_stdio(false);
    x=(1+sqrt(5.0))/2.0;
    while(sd2(a,b)!=EOF){
        
        m=min(a,b);
        n=max(a,b);
        
        c=n-m;
        if((int)(x*c)==m) printf("0\n");
        else printf("1\n");
    }
}
