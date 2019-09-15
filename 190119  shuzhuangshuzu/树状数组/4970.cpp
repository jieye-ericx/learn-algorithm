#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100005;
int n;
long long c[N],sum[N];
int lowbit(int x){
    return x&(-x);
}

void add(int x,int y){
    while(x<=n) {
        c[x]+=y;
        x+=lowbit(x);
    }
}

long long getSum(int x)
{
    long long ans = 0;
    while(x>0) {
		ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
	int m,l,r,d,num=0;
	while(~scanf("%d",&n)&&n){
		num=0;
		scanf("%d",&m);
		memset(c,0,sizeof(c));
		memset(sum,0,sizeof(sum));
		long long h;
		int x;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&l,&r,&d);
			add(l,d);
			add(r+1,-d);
		}
		scanf("%d",&m);
		sum[n+1]=0;
		for(int i=n;i>=1;i--){
				sum[i]=sum[i+1]+getSum(i);
			}
		for(int i=0;i<m;i++){
			scanf("%lld%d",&h,&x);
			if(sum[x]<h){
				num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
