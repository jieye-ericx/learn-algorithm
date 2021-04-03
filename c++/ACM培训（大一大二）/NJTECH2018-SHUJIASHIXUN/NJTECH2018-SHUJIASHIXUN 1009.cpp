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
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define p(a) printf("%d\n",a)

int a[500004];
int n,b,i,j,down,up,max1,sum,mid;

int main(){
	//ios::sync_with_stdio(false);
	while(sd2(n,b)&&(n!=-1&&b!=-1)){
		max1=0;
		/////////////////
		for(i=0;i<n;i++) {
			sd1(a[i]);
			if(a[i]>max1) max1=a[i];
		}
		up=max1;down=1;sum=0;
		while(down<=up){
			j=0;
			mid=(up+down)>>1;
			for(i=0;i<n;i++){
				j+=ceil(a[i]*1.0/mid);
			}
			if(j>b){
				down=mid+1;
			}else {
				up=mid-1;
				sum=mid;
			}
			
		}
		p(sum);
	}
	return 0;
}


