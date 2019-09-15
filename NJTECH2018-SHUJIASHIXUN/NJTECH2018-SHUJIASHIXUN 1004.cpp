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

long long k,n,i,j,sum;
double meter;
double centimeter[10005],minx,up,down,mid;
int main(){
	//ios::sync_with_stdio(false);
	while(sd2(n,k)!=EOF&&n+k){
		minx=0;
		for(i=0;i<n;i++){
			scanf("%lf",&meter);
			//cout<<meter*100<<endl;
			centimeter[i]=meter*100;
			if(centimeter[i]>minx) minx=centimeter[i];
		}
		
		up=minx;
		down=1;
		//
		
		//
		while(down<=up){
			sum=0;
			mid=(down+up)/2.0;
			for(i=0;i<n;i++){
				sum+=floor(1.0*centimeter[i]/mid);
			}
			if(sum==k){
				//break;
				down=mid+1;
			}else if(sum>k){
				down=mid+1;
			}else{
				up=mid-1;
			}
		}
		double elt=1.0*mid/100;
		printf("%.2lf\n",elt);
		
		

		
		//for(i=0;i<n;i++)cout<<centimeter[i]<<endl;


	}
	return 0;
}


