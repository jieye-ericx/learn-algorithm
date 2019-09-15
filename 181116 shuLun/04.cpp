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
//15x=5(mod10) 15x+10y=5;
//15x0+10y0=d,d=gcd()
int main(){
    int a,b,m,d,x0,y0,i;
    cin>>a>>b>>m;
    d=extend_gcd(a,m,x0,y0);
    if(b%d){
        cout<<"no"<<endl;
        return 0;
    }
    cout<<"ans="<<endl;
    for(i=0;i<d;i++){
        cout<<(x0*b/d+i*m/d)<<' ';
    }
    cout<<endl;
    system("pause");
    return 0;
}