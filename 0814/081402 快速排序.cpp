#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;

#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define p(a) printf("%d\n",a)

int partition(int a[],int left,int right){
	
	int k=left+rand()%(right-left+1);
	swap(a[k],a[left]);
	int x=a[left],i=left,j=right;
	while(1){
		while(a[++i]<x);
		while(a[--j]>x);
		if(i>j) break;
		swap(a[i],a[j]);
	}
	a[left]=a[j];
	a[j]=x;
	return j;
}

void qSort(int a[],int left,int right){
	int m;
	if(left>=right) return;
	m=partition(a,left,right);
	qSort(a,left,m);
	qSort(a,m+1,right);
}

int main(){
	//ios::sync_with_stdio(false);
	int a[]={2,5,1,2,9,6,7};
	int c=2,d=10;
	srand(time(0));
	
	qSort(a,0,7);
	for(int i;i<7;i++)cout<<a[i]<<endl;
	
	return 0;
}


