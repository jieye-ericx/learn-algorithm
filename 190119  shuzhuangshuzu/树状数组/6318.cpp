#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N = 5e5+10;
int n;
ll c[N];
int a[N],b[N];
map<int,int> ma;

int lowbit(int x){
    return x&(-x);
}
void add(int x,int d){
    for (int i=x;i<=n;i+=lowbit(i)){
        c[i]+=d;
    }
}
ll getsum(int x){
    ll ans=0;
    for (int i=x;i>0;i-=lowbit(i))
        ans+=c[i];
    return ans;
}


int main(){
    ll x,y;
    while(scanf("%d %lld %lld",&n,&x,&y)!=EOF){
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int cnt=1;
        ma.clear();
        for(int i=1;i<=n;i++)
            ma[b[i]]=cnt++;
        for(int i=1;i<=n;i++)
            a[i]=ma[a[i]];
        memset(c,0,sizeof(c));

        ll ans=0;
        for (int i=n;i>=1;i--){
            ans+=getsum(a[i]-1);
            add(a[i],1);
        }
        printf("%lld\n",ans*min(x,y));
    }
    return 0;
}

