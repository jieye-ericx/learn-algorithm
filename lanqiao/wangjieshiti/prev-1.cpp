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

int a,b,c,t,i;
int main(){
	//ios::sync_with_stdio(false);
 	scanf("%d%d%d",&a,&b,&c);
	if(a>b){
		t=a;
		a=b;
		b=t;
	}
	if(c<b){
		t=c;
		c=b;
		b=t;
	}
	if(b<a){
		t=a;
		a=b;
		b=t;
	}
	for(i=c;;i+=c){
		if(i%a==0&&i%b==0){
			printf("%d\n",i);
			break;
		}
		
	}
	return 0;
}


