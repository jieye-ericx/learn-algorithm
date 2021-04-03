#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define p(a) printf("%d\n",a)
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define UP 100000.0
struct point{
	double x,y;
};

int a,b,c;
point p;
double f(double x){
	return a*x*x+b*x+c;
}

double dis(point p1,point p2){
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

double triSearch(double left,double right){
	
	
	double lm=left+(right-left)/3,rm=right-(right-left)/3;
	point p1,p2;
	p1.x=lm;p1.y=f(lm);
	p2.x=rm;p2.y=f(rm);
	if(abs(right-left)<1e-6){
		return dis(p1,p);
	}
	if(dis(p1,p)<dis(p2,p)){

		triSearch(left,rm);
	}else{
		triSearch(lm,right);
	}
}

int main(){
	//ios::sync_with_stdio(false);
	
	double t;
	
	cin>>a,b,c;
	cin>>p.x>>p.y;
	t=-1.0*b/2/a;
	if(p.x>=t){
		triSearch(t,UP);
	}else{
		triSearch(-UP,t);
	}


	return 0;
}


