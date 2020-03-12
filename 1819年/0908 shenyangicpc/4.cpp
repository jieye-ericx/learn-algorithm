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

int n,m,s,e,k,t,u,v,w;
int min;
int main(){
    
    while(scanf("%d%d",&n,&m)!=EOF){
        min=0;
        //
        scanf("%d%d%d%d",&s,&e,&k,&t);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            
        }
        //while(cin>>a&&a!='\0'){
            for(i=n;i>=1;i--){
                if(isprime(i)){
                    for(t=i;t&&isprime(t%10);t/=10);
                    if(!t){
                        printf("%d\n",i);
                        flag=1;
                    }
                }
                if(flag==1) break;
            }
        //}
    }

    system("pause");
    return 0;
}
