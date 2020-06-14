#include<stdio.h>
#include<string.h>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
using namespace std;

struct point
{
    int x,y;
};
double k;
// point p1,p2,a;
// int flag;
// int x,y;
// void cmp(point p1,point p2){
//     a.x=p2.x-p1.x;
//     a.y=p2.y-p1.y;
//     int i,j;
//     if(a.x>0&&a.y>0){
//         for(i=p2.x,i)
//         flag=1;
//     }else if(a.x>0&&a.y<0){
//         flag=4;
//     }else if(a.x<0&&a.y>0){
//         flag=2;
//     }else flag=3;
//     if( (p2.y-p1.y)*(x-p1.x)==(p2.x-p1.x)*(y-p1.y)){
//         return ;
//     }
// }
// int main(){
//     ios::sync_with_stdio(false);
//     while(cin>>p1.x>>p1.y>>p2.x>>p2.y){
        
//     }
//     return 0;
// }


#include <stdio.h>
#include <math.h>
 
int gcd(int a,int b){
	if(0==b) return a;
	return gcd(b,a%b);
}
 
void solve(){
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	int dy=y2-y1,dx=x1-x2,gcdxy=gcd(fabs(dx),fabs(dy));
	printf("%d %d\n",x2+dy/gcdxy,y2+dx/gcdxy);
}
 
int main(){
	while(1){
solve();
    }
	return 0;
}
