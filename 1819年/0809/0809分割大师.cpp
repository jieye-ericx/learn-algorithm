#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 242
char dig[N];
int s;
char pre;
int main(){
	ios::sync_with_stdio(false);
	int n,i;
	cin>>s;
	n=strlen(s);
	while(s--){
		for(i=1;i<n;i++){
			if(a[i]=='#')
				continue;
			else 
				pre=a[i];
			if(a[i]<pre){
				a[i]='#';
				break;
			}
			else
				pre=a[i];
		}
	}
	return 0;
}


