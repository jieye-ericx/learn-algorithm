#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define sd1(a) scanf("%d",&a)
#define slld1(a) scanf("%lld",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pd1(a) printf("%d\n",a)
#define plld1(a) printf("%lld\n",a)

int n,m,i,x,y,sum;
int main(){
    while(sd2(n,m)!=EOF){
        //scanf("%d%d",&n,&m)!=EOF){
        sum=0;
        for(i=0;i<n;i++){
        //scanf("%d%d",&x,&y);
        sd2(x,y);
        sum=sum^abs(x-y)-1;
        }
        if(sum==0) printf("BAD LUCK!\n");
        else printf("I WIN!\n");
    }
    return 0;
}