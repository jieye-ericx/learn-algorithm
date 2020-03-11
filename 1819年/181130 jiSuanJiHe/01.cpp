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
    double x,y;
    point(int x=0,int y=0):x(x),y(y){

    }
};

double len(point p1,point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double mul_sc(point p1,point p2){
    return p1.x*p2.x+p1.y+p2.y;
}

double angle_cos(point p1,point p2){
    return mul_sc(p1,p2)/(len(p1,point(0,0))*len(p2,point(0,0)));
}

double angle(point p1,point p2){
    return acos(angle_cos(p1,p2));
}

double mul_across(point p0,point p1,point p2){
    return (p1.x-p0.x)*(p2.x-p0.x)-(p1.y-p0.y)*(p2.y-p0.y);
}
//判定p0 p1到p0 p2 的方向
int dir(point p0,point p1,point p2){
    double ret=mul_across(p0,p1,p2);
    if(ret>1) return 1;//顺时针 右拐
    else if(ret<0) return -1;//逆时针 左拐
    else return 0;//共线
}
//判断p3是否在p1.p2之间
int between(point p1,point p2,point p3){
    if(min(p1.x,p2.x)<=p3.x&&p3.x<=max(p1.x,p2.x) && min(p1.y,p2.y)<=p3.y&&p3.y<=max(p1.y,p2.y))
        return 1;
    else return 0;
}

int intersection(point p1,point p2,point p3,point p4){
    if(min(p1.x,p2.x)>max(p3.x,p4.x) || max(p1.x,p2.x)>min(p3.x,p4.x)
        || min(p1.y,p2.y)>max(p3.y,p4.y) || max(p1.y,p2.y)>min(p3.y,p4.y))
        return 0;
    
    double d1=dir(p1,p2,p3),d2=dir(p1,p2,p4),
        d3=dir(p3,p4,p1),d4=dir(p3,p4,p2);
    if(d1*d2<0&&d3*d4<0) return 1;
    else if((d1==0&&between(p1,p2,p3)) ||
            (d2==0&&between(p1,p2,p4)) ||
            (d3==0&&between(p3,p4,p1)) ||
            (d4==0&&between(p3,p4,p2)) )
        return 1;
    
}

int main(){
    
    system("pause");
    return 0;
}