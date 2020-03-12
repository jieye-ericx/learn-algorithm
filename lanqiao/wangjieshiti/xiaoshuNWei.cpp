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
int a,b,n;
int main(){
    while(cin>>a>>b>>n){
        int ca=a,cn=n,cnt=0;
        while(cn--){
            if(!ca) break;
            if(ca>=b){
                ca=ca%b;
                ca*=10;
            }else if(ca<b){
                ca*=10;
            }
            cnt++;
            if(ca%b==a) cn=n%cnt;
        }
        if(!ca) cout<<"000"<<endl;
        else {
            cout<<ca/b;
            ca=ca%b*10;
            cout<<ca/b;
            ca=ca%b*10;
            cout<<ca/b<<endl;
        }
    }

    system("pause");
    return 0;
}