#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e9+7;
long long c[1005][1005];
void init()
{
    memset(c,0,sizeof(c));
    c[0][0]=c[1][0]=c[1][1]=1;
    for(int i=2;i<=1005;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
        c[i][j]=(c[i-1][j]+c[i-1][j-1])%maxn;
    }
}
int main()
{
    int t;
    cin>>t;
    init();
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%lld\n",c[max(m,n)][min(n,m)]);
    }
    return 0;
}
