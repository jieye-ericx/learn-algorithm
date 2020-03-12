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

int n;long long k;char a[105];
int main(){
	//ios::sync_with_stdio(false);
	while(cin>>a>>k){
		for(n=0;n<strlen(a);n++){
			if(a[n]-'0'==1&&k!=n) continue;
				cout<<a[n]<<endl;
				break;

		}


	}
	return 0;
}


