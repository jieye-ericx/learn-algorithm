/********************
���ַ� 
************************/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 10
int main(){
	ios::sync_with_stdio(false);
	int a[N]={0,1,2,3,4,5,6,7,8,9} ;
	int t;
	while (cin>>t){
	int left=0,right=N-1,mid;
	while(left<=right){
		mid=(left+right)/2;
		if(a[mid]==t) 	{
		
		cout<<"a["<<mid<<"]="<<t<<endl;
		break;
		}
		if(t>a[mid]) left=mid+1;
		else  if(t<a[mid]) right=mid-1;
	}
}
	return 0;
}


