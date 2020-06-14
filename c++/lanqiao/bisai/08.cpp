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
#define N 100007

// int a[N][2];
int i,j,k,n;
struct c
{
    int a,b;
}cs[N];
bool tmp(c c1,c c2){
    return c1.a<c2.a;
}
bool tmp1(c c1,c c2){
    return c1.b<c2.b;
}
int t;
int main(){
    ios::sync_with_stdio(false);

    //
    while(cin>>n){
        for(i=0;i<n;i++){
            cin>>cs[i].a;
        }
        for(i=0;i<n;i++){
            cin>>cs[i].b;
        }
        for(i=0;i<n;i++){
            if(cs[i].a>cs[i].b){
                t=cs[i].b;
                cs[i].b=cs[i].a;
                cs[i].a=t;
            }
        }
        sort(cs,cs+n,tmp);
        // for(i=1;i<n;i++){
        //     cout<<cs[i].a<<" "<<cs[i].b<<endl;
            
        // }
        for(i=1;i<n;i++){
            if(cs[i-1].a>i) break;
            if(cs[i].a==cs[i-1].a){
                for(j=i+1;j<n;j++){
                    if(cs[j].a!=cs[i].a) break;
                }
                //cout<<j-i+1<<endl;
                sort(cs+i-1,cs+j,tmp1);
                for(k=i-1;k<j-1;k++){
                    t=cs[k].b;
                    cs[k].b=cs[k].a;
                    cs[k].a=t;
                }
                sort(cs+i-1,cs+n,tmp);
            }
        }
        for(i=0;i<n;i++){
            if(cs[i].a>i+1) break;
        }
        cout<<i+1<<endl;
    }
    
    system("pause");
    return 0;
}
/*
5  
1 2 3 5 6  
3 4 3 4 4
6
1 2 3 5 6 7  
3 4 3 4 4 4
*/