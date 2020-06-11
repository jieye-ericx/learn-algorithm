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

int extend_gcd(int a,int b,int &x,int &y){
    if(a==0&&b==0) return -1;
    else if(b==0) {
        x=1;
        y=0;
        return a;
    }
    int t,d;
    d=extend_gcd(b,a%b,x,y);
    t=x;x=y;y=t-(a/b)*y;
    return d;
}

int main(){
    int a,b,m,d,x0,y0,i;
    //ax=1(mod m)
    cin>>a>>m;
    d=extend_gcd(a,m,x0,y0);
    if(d!=1) {
        cout<<"wujie"<<endl;
        return 0;
    }
    cout<<"ans="<<endl;
    cout<<(x0+m)%m<<' ';
    cout<<endl;
    system("pause");
    return 0;
}