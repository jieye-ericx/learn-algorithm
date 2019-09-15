#include <iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;

int f(int n){
    int i,s=1;
    for(i=1; i<=n; i++)
        s=s*i;
    return s;
}

int m,i,j,t,k,num[12],x;
double c1[12],c2[12];//因为用到了除法，所以用double型来存储。
long long int n;
int main(){
    

    while(scanf("%d",&t),t){
        x=1;
        while(t--){
            printf("Case %d: ",x++);
            memset(c1,0,sizeof(c1));
            memset(c2,0,sizeof(c2));
            // for(i=0; i<n; i++){
            //     cin>>num[i];
            // }
            scanf("%lld",&n);
            for(i=0; i<=num[0]; i++)//赋初值
                c1[i]=1.0/f(i);
            for(i=1; i<=4; i++){//n个括号
                for(j=0; j<=n; j++)
                    for(k=0; k<=num[i]&&k+j<=n; k++)
                        c2[k+j]+=c1[j]/f(k);
                for(j=0; j<=n; j++){
                    c1[j]=c2[j];
                    c2[j]=0;
                }
            }

            printf("%.lf\n",c1[m]*f(m));
        }
        

    }

    return 0;

}


