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
int a[1000006];
int i,t,n;
long long num,ji,ou;
int main(){
    
    scanf("%d",&t);
    while(t--){
        ji=0;ou=0;
        ///////////
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&num);
            if(num&1) {
                a[i]=1;
                ji++;
            }else {
                ou++;
                a[i]=0;
            }
        }
        if(ou==n) printf("xf\n");
        else printf("xm\n");
    }

    //system("pause");
    return 0;
}