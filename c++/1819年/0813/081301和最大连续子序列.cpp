#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int maxSeg(int a[],int left,int right,int &e,int &b){
	int mid=(left+right)>>1,ret,max1,max2;
	if(left==right)
		return a[left];

	max1=maxSeg(a,left,mid,e,b);
	max2=maxSeg(a,mid+1,right,e,b);
	ret=max(max1,max2);
	int tmp1,tmp2,ret1=0,ret2=0,i;
	tmp1=a[mid];
	for(i=mid-1;i>=0;i--){
		tmp1+=a[i];
		if(tmp1>ret1)
			{
				cout<<i;
				ret1=tmp1;
				e=i;
			}
	}
	tmp2=ret2=a[mid+1];
	for(i=mid+2;i<right;i++){
		tmp2+=a[i];
		if(tmp2>ret2)
			{
				ret2=tmp2;
				b=i;
			}
	} 
	ret=max(ret,ret1+ret2);
	
	return ret;
}
#define N 100003
int a[N];
int main(){
	//os::sync_with_stdio(false);
	int i,j,k,n;int e,b;
	int t;scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++) scanf("%d",&a[j]);


		printf("Case %d:\n",i);
		printf("%d %d %d",maxSeg(a,0,n,e,b),e,b);
		if(i!=t-1)printf("\n");
	}
	
	 
	return 0;
}


