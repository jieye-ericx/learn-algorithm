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
#define N 100002

int a[N];
int n,m;

int main(){
	//ios::sync_with_stdio(false);
	int i,sum=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int left=0,right=sum,mid,ml,st,suml;
	while(left<right){
		mid=(left+right)>>1;
		ml=m;
		st=0;
		suml=0;
		while(ml--){
			for(i=st;i<n;i++){
				suml+=a[i];
			}
		}
	}
	
	return 0;
}


