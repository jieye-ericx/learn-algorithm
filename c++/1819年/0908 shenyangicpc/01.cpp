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
int t,n,x,A,B;
int a[10005],i,j,num;
int main(){
    scanf("%d",&t);
    while(t--){
        num=0;
        memset(a,0,sizeof(a));
        //
        scanf("%d%d",&n,&x);
        scanf("%d%d",&A,&B);
        for(i=0;i<A;i++){
            scanf("%d",&j);
            a[j]++;
        }
        //
        if( !(n%(x+1)) ){
            if(a[n/(x+1)*2]){
                num=1;
            }else{
                num=0;
            }
            //后手必赢
        }else {
            if(a[n/(x+1)*2+1]){
                num=1;
            }else{
                num=0;
            }
        }
        //
        if(num) printf("Gudako\n");
        else printf("Ritsuka\n");
    }

    system("pause");
    return 0;
}