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

int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int x,y;
int main(){
	//ios::sync_with_stdio(false);
	while(cin>>x>>y)
	cout<<gcd(x,y);
	return 0;
}


