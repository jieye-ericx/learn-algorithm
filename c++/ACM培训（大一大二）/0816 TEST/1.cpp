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

long long n,t,sum,i,j,k,a[44]={0};
int main(){
	//ios::sync_with_stdio(false);
	//sd1(t);
	a[0]=1;
	for(j=1;j<40;j++){
		a[j]=a[j-1]*2;
		//cout<<j<<" "<<a[j]<<endl;
	}
	//cout<<upper_bound(a,a+40,513)-a<<endl;
	
	//while(t--){
	// 	sum=0;
	// 	sd1(n);
	// 	sum=((1+n)*n)>>1;
	// 	k=upper_bound(a,a+40,n)-a;
	// 	for(i=0;i<k;i++)
	// 	{
	// 		sum=sum-2*a[i];
	// 	}
	// 	plld1(sum);
	// }
	if(1) int m=10;
	cout<<m;
	system("pause");
	return 0;
}


