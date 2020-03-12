#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
#define N 20004
int a[N];
int n,m,i;

//set<int> mp;

int main(){
	//ios::sync_with_stdio(false);
	while(~scanf("%d%d",&n,&m)){
	//mp.clear();
	for(i=0;i<n+m;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+m+n);
	//mp.insert(a,a+m+n);
	//set<int>::iterator ite1;
	//for(ite1=mp.begin();ite1!=mp.end();ite1++){
	//	if(ite1==mp.begin()) printf(" %d",*ite1);
	//	else printf(" %d",*ite1);
	//}
	printf("%d",a[0]);
	for(i=1;i<m+n;i++){
		if(a[i]!=a[i-1])
			printf(" %d",a[i]);
	}
	printf("\n");
}
	return 0;
}


