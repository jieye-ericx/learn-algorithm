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

int isprime(int n)
{for(int i=2;i*i<=n;i++)
   if(n%i==0)return 0;
 return n>1;  
} 
//int main() 
//{int i,a,b,c,t; 
// scanf("%d%d",&a,&b);
// for(i=a;i<=b;i++)
//   if(isprime(i))
//   {for(t=i;t&&isprime(t%10);t/=10);
//    if(!t)printf("%d\n",i);
//   }
// return 0; 
//}
int x,t,flag;
long long n;
int i,j,num;
char a;
int main(){
    scanf("%d",&x);
    while(x--){
        flag=0;
        scanf("%lld",&n);
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
