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
int n,i,cnt,sta,t,ans1,ans2,flag;
int vis[100002];
int a[100000];
int main(){
	//ios::sync_with_stdio(false);
	cin>>t;
	cnt=0;
	while(cin>>n){
		a[cnt++]=n;
	}
	for(i=0;i<cnt;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}


