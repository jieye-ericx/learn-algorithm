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
int n,i,j,mmax,mmin,ans,a[50005];
int main(){
	//ios::sync_with_stdio(false);
	ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		mmin=50005;
		mmax=0;
		for(j=i;j<n;j++){
			mmin=min(mmin,a[j]);
			mmax=max(mmax,a[j]);
			if(j-i==mmax-mmin) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}


