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
using namespace std;
int a[11],b[11];
int t,n,m,x;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void com(int x){
    for(int i=1;i<=x;i++){
        b[i]++;
    }
}
int main(){
    cin>>t;
    while(t--){
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        //
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>a[i];
        }
        sort(a,a+m);
        for(int i=0;i<m-1;i++){
            com(a[i+1]-a[i]);
        }
        com(a[0]+n-a[m-1]);
        
        //last=x;
        //cin>>x;
        //com(x-last);
        //com(fir+n-x);
        int p;
        for(int i=1;i<=n;i++){
            if(b[i]!=0){
                p=gcd(b[i],n);
                cout<<b[i]/p<<"/"
                <<n/p<<"\n";

            }else{
                cout<<"0\n";
            }
        }
    }
    system("pause");
    return 0;
}