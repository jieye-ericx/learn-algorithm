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



int f(long long x){
    int tmp = (x+1)%4;
    if(tmp==0){
        return 0;
    }else if(tmp==1){
        return x;
    }else if(tmp==2){
        return x^(x-1);
    }else 
        return x^(x-1)^(x-2);
}

long long ni,xi,ret=0;int n,t;
int main(){
        cin>>t;
        while(t--){
        cin>>n;
        while(n--){
            cin>>ni>>xi;
            ret=ret^f(xi+ni-1)^f(xi-1);
        }
        if(!ret) cout<<"lose"<<endl;
        else cout<<"win"<<endl;
    }
    //system("pause");
    return 0;
}