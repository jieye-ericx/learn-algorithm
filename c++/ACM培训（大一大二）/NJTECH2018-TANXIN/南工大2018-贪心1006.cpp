#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map> 
using namespace std;
#define N 100000000
map<int ,long long int>mp;
int main(){
	
	int i,k,n,max;
	while(~scanf("%d",&n)){
		mp.clear();
		////////////
		for(i=0;i<n;i++) {
			scanf("%d",&k);
			mp[k]++;
		}
		max=0;
		map<int,long long int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++) {
			if(max<it->second)
				max=it->second;
		}
		printf("%d\n",max);

	}
	return 0;
}


