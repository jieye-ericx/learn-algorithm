
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

int l,n,m,i;
long long j,max1,down,up,mid,sum,suml;
long long dis[500004],a[500004];
int cha(long long mid){
	int cut=0;int last=0;
	for(i=1;i<=n+1;){
		if(last+mid>=a[i]){
			i++;
		}else{
			if(last==a[i-1]){
				return false;
			}
			last=a[i-1];
			cut++;
		}
	}
	cut++;
	return cut<=m;
}
int main(){
	//ios::sync_with_stdio(false);
	
	while(~sd3(l,n,m)){
		dis[0]=0;a[0]=0;
		max1=0;sum=0;
		/////////////
		for(i=1;i<=n;i++){
			slld1(a[i]);
		}
		a[n+1]=l;
		sort(a,a+n+1);
		//for(i=0;i<=n+1;i++){
		//	pd1(a[i]);
		//}cout<<endl;
		for(i=1;i<=n+1;i++){
			dis[i]=a[i]-a[i-1];
			if(dis[i]>max1)max1=dis[i];
		}
		//for(i=0;i<=n+1;i++){
		//	plld1(dis[i]);
		//}cout<<endl;
		//cout<<max1<<endl;

		up=l;down=1;
		while(down<=up){
			//sum=0;//suml=0;
			mid=(down+up)>>1;
   			//for(i=1;i<=n+1;i++){
			//	sum+=ceil(1.0*dis[i]/mid);
			//}
			//if(sum>m){
			if(!cha(mid)){
				down=mid+1;
			}else{
				up=mid-1;
				suml=mid;
			}
		}
	
		plld1(suml);
	}
	return 0;
}


