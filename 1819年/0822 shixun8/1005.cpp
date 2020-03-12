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
#define N 21
int primelist[38] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};
int a[N],x[N];
int n,cnt=1;
void dfs(int dep){
	int i;
	if(dep>=n&&primelist[a[0] + a[n-1]]){
		cout<<a[0];
		for(i=1;i<n;i++){
			cout<<" "<<a[i];
		}
		cout<<endl;
		return ;
	}
	for(i=2;i<=n;i++){
		if(!x[i]&&primelist[i+a[dep-1]]){
			a[dep]=i;
			x[i]=1;
			dfs(dep+1);
			x[i]=0;
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);

	a[0]=1;
	while(~scanf("%d",&n)){
		memset(x,0,sizeof(x));
		cout << "Case " << cnt++ <<":\n";
		dfs(1);
		cout<<endl;
	}
	return 0;
}


