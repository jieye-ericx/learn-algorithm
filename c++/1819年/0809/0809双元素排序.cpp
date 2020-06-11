#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 100003
struct node{
	int start;
	int end;
	int index;
}ev[N]; 

bool cmp(const node n1,const node n2){
	if(n1.end==n2.end)
		return n1.start<n2.start;
	return n1.end<n2.end;
}	

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ev[i].start>>ev[i].end;
		ev[i].index=i; 
	}
	sort(ev,ev+n,cmp);
	return 0;
}


