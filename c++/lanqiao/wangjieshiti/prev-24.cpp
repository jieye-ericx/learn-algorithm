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

#define N 10
struct node{
	int x,y;
} cm[N],yj[N];
bool tmp(node n1,node n2){
	if(n1.x!=n2.x) return n1.x<n2.x;
	return n1.y<n2.y;
}
int a[N],b[N],n,m,k,x,y,i,j;
double mindis,finals=0xffffff,sum=0,mmm;
int main(){
	//ios::sync_with_stdio(false);
	sd3(n,m,k);
	for(i=0;i<n;i++){
		sd2(x,y);
		cm[i].x=x;
		cm[i].y=y;
	}
	for(i=0;i<m;i++){
		sd2(x,y);
		yj[i].x=x;
		yj[i].y=y;
		a[i]=i;
	}
	sort(cm,cm+n,tmp);
	sort(yj,yj+m,tmp);
//	for(i=0;i<n;i++){
//		cout<<cm[i].x<<" "<<cm[i].y<<endl;
//	}
//	cout<<endl;
//	for(i=0;i<m;i++){
//		cout<<yj[i].x<<" "<<yj[i].y<<endl;
//	}
	do{
		sum=0;
		for(i=0;i<n;i++){
			mindis=0xFFFFFF;
			for(j=0;j<k;j++){
				mmm=sqrt((cm[i].x-yj[a[j]].x)*(cm[i].x-yj[a[j]].x)+(cm[i].y-yj[a[j]].y)*(cm[i].y-yj[a[j]].y));
				mindis=min(mindis,mmm);
			}
			sum+=mindis;
		}
		if(sum<finals){
			finals=sum;
			for(i=0;i<k;i++){
				b[i]=a[i];
			}
		}
		
	}while(next_permutation(a,a+m));
	for(i=0;i<k;i++){
		printf("%d ",b[i]+1);
	}
	
	return 0;
}


