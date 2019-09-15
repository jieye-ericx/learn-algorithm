#include <iostream>

using namespace std;

int extend_gcd(int a,int b,int x,int y){
    if(a==0&&b==0) return -1;
    if(a!=0&&b==0) {
        x=1;
        y=0;
        return a;
    }
    int t,d;
    d=extend_gcd(b,a%b,x,y);
    t=x;x=y;y=t-(a/b)*y;
}