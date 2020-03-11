#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <map>
using namespace std;
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define p(a) printf("%d\n",a)
#define N 10005
int a[N],b[N],c[N];
int n,t,j,cnt;
double le,ri,lm,rm;

double  f(double x){
    int i;double max=a[0]*x*x+b[0]*x+c[0];
    for(i=1;i<n;i++){
        if(max<a[i]*x*x+b[i]*x+c[i]) max=a[i]*x*x+b[i]*x+c[i];
    }
    return max;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d%d%d",&a[j],&b[j],&c[j]);
        }
        le=0;ri=1000;
        cnt=0;
        while(cnt++<100){
            lm=le+(ri-le)/3;
            rm=ri-(ri-le)/3;
            if(f(lm)<f(rm)){
                ri=rm;
            }else {
                le=lm;
            }
        }
        printf("%.4lf\n",f(lm));

    }
    return 0;
}
