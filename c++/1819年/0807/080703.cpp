#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int ord(int n){//c1=(p1+p2+p4)%4  Çóp4µÄÖµn=c1-p1-p2 
	if(n>0)
		return n%4;
	else{
	 while(n<0) n+=4;
	 	return n;
	} 
}

int main(){
	ios::sync_with_stdio(false);
	
	return 0;
}


