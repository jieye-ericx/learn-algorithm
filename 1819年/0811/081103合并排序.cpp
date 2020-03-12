#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int a[]={6,2,3,4,5,8,1,10,9};
int len=sizeof(a)/sizeof(int);
int merge(int left,int mid,int right){
	int i=left;int j=mid+1;
	int *b =new int[right-left+1],cnt=0;
	while(i<=left||j<=right){
		if(a[i]<a[j]){
			b[cnt++]=a[i];
			i++;
		}else if(a[i]>=a[j]||i==mid+1){
			b[cnt++]=a[j];
			j++;
		}
	}
	foe(i=left;i<=right;i++){
		a[i]=b[left-i];
	}
	delete b;
}
void mergeSort(int left,int right){
	if(left>=right) return;
	
	int mid=(left+right)>>1;
	mergeSort(left,mid);
	mergeSort(right,mid+1);
	merge(left,mid,right);
}
 
int main(){
	ios::sync_with_stdio(false);
	mergeSort(0,len);
	for(int i=0;i<len;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}


