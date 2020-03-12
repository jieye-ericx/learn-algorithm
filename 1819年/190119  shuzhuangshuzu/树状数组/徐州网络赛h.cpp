#include<bits/stdc++.h>
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int mod = 1e9+7;
const int MXN = 1e6 + 7;
int n, m;
LL bit[MXN], ar[MXN], hh[MXN];
int lowbit(int x){return (x&(-x));}
void add(int x,LL c){for(;x <= n;x += lowbit(x)) bit[x]+=c;}
LL query(int x){LL ans = 0;for(;x;x -= lowbit(x))ans+=bit[x];return ans;}
void add1(int x,LL c){for(;x <= n;x += lowbit(x)) hh[x]+=c;}
LL query1(int x){LL ans = 0;for(;x;x -= lowbit(x))ans+=hh[x];return ans;}
int main(){
    while(~scanf("%d%d", &n, &m)){
        memset(bit,0,sizeof(bit));
        memset(hh,0,sizeof(hh));
        for(int i = 1; i <= n; ++i){
            scanf("%lld", &ar[i]);
        }
        reverse(ar+1, ar + 1 + n);
        for(int i = 1; i <= n; ++i){
            add(i, ar[i]);
            add1(i, ar[i]*i);
        }
        int op, x, y, l, r;
        for(int t = 0; t < m; ++t){
            scanf("%d%d%d", &op, &x, &y);
            if(op == 1){
                l = n + 1 - y; r = n + 1 - x;
                LL ans = query1(r) - query1(l-1);
                ans -= (query(r) - query(l-1))*(l-1);
                printf("%lld\n", ans);
            }else{
                x = n + 1 - x;
                add(x, y - ar[x]);
                add1(x, x*(y - ar[x]));
                ar[x] = y;
            }
        }
    }
    return 0;
}
