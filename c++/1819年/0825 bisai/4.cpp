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

int main(){
    int t;
    long long n;int a,k,t1,t2;
    scanf("%d",&t);
    while(t--){
        cin>>n>>a;
        if(n>2||n==0){
            cout<<-1<<' '<<-1<<endl;
            continue;
        }else if(n==1){
            cout<<1<<' '<<a+1<<endl;
        } else if(n==2){
            if(a&1){
                cout<<(a*a-1)/2<<' '<<(a*a+1)/2<<endl;
            }
            else{
                k=0;
                while(!(a&1)){
                    k++;a/=2;
                }
                t1=(a*a-1)/2;
                t2=(a*a+1)/2;
                t1=t1*(1<<k);
                t2=t2*(1<<k);
                cout<<t1<<' '<<t2<<endl;
            }
        }

    }

    //system("pause");
    return 0;
}