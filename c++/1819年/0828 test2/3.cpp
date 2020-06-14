#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
int t,n,i,e,ty,k,num;
int a[100004],b;

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
int main(){
    scanf("%d",&t);
    
    while(t--){
        e=0,b=0;
        memset(a,0,sizeof(a));
        ///
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        
        for(i=1;i<=n;i++){
            scanf("%d",&b);
            a[b]=-100000000;
			//num=0;
            ty=maxSeg(a,1,n,e,b);
			//for(k=1;k<=n;k++){
			//	if(a[k]<0) {
			//		num=0;continue;
			//	}
			//	num+=a[k];
			//	if(num>ty) ty=num;
			//}
			if(ty<0) ty=0;
			printf("%d\n",ty);
        }

    }
    system("pause");
    return 0;
}