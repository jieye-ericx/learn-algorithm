#include <iostream>
#define ll long long
using namespace std;
ll tmp[100];
ll count_ans(ll x){
    ll ans=0,cnt;
    for(int i=0;tmp[i]<=x;i++){
        ans=ans+((x/tmp[i]-x/tmp[i+1])*tmp[i]);
    }
    return ans;
}
int main(){
    ll n,a,b;
    int m,x;
    tmp[0]=1;
    for(int i=1;i<63;i++) tmp[i]=tmp[i-1]*2;

    while(~scanf("%lld%d",&n,&m)){
        while(m--){
            scanf("%d",&x);
            if(x==1){
                scanf("%lld%lld",&a,&b);
                printf("%lld\n",count_ans(b)-count_ans(a-1));
            }
            if(x==2){
                scanf("%lld",&a);
                int ans=0;
                while(a<=n){
                    ans++;
                    a+=(a&(-a));
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
