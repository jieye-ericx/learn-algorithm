#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100005
int c[N],b[N];
int n,x,y,j,sum,cnt;
long long int mon;

struct node
{
    int i,k;
    bool operator < (const node &a) const{
        if(k != a.k) return k < a.k;
        return i < a.i;
    }
}p[N];

int lowbit(int x){
    return x&(-x);
}
void add(int x,int y){
    while(x<=n) {
        c[x]+=y;
        x+=lowbit(x);
    }
}
int getSum(int x){
    int ans = 0;
    while(x>0) {
		ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
	while(scanf("%d%d%d",&n,&x,&y)!=EOF){
		memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        memset(p,0,sizeof(p));
        sum=0;
        cnt=1;
        //
        for(j=1;j<=n;j++){
            scanf("%d",&p[j].k);
            p[j].i=j;
        }
        sort(p+1,p+n+1);
        for(j=1;j<=n;j++){
            if(j!=1&&p[j].k!=p[j-1].k) cnt++;
            b[p[j].i]=cnt;
        }
        //cout<<mina<<" "<<maxa;
        for(j=1;j<=n;j++){
            add(b[j],1);
            sum+=j-getSum(b[j]);
        }
        mon=sum*min(x,y);
        printf("%lld\n",mon);
		
	}
	return 0;
}
