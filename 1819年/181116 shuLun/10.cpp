#include <iostream>

using namespace std;
#define LL long long
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}

LL mod(LL a,LL b,LL c){
    LL ret=0,t=a;
    while(b){
        if(b&1) ret+=t;
        ret%=c;
        t<<=1;
        t%=c;
        b>>=1;
    }
    return ret;
}
LL factor(int n,int k){
    int x2,x1=rand()%n,p;
    while(1){
        x2=(mod(x1,x1,n)+k)%n;
        p=gcd(abs(x2-x1),n);
        if(p==n) return 0;
        if(p>1){
            return p;
        }
        if(x2==x1) return -1;
        x1=x2;
    }
}

LL f[];
int cnt=0;
void all_factor(LL n){
    LL p;
    p=factor(n,1);
    if(p==0){
        f[cnt++]=n;
    }else if(p>0){
        all_factor(p);
        all_factor(n/p);
    }else{
        all_factor(n);
    }
}

int main(){
    all_factor(1000);
    for(int i=;i<cnt;i++){
        cout<<f[i]<<" ";
    }
}