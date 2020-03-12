#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100004
int i,j,k,n;
int a[N],b[N],c[N];
long long int ans;
int main(){
    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++) scanf("%d",&b[i]);
        for(i=0;i<n;i++) scanf("%d",&c[i]);

        sort(a,a+n),sort(b,b+n),sort(c,c+n);

        for(i=0;i<n;i++){
            ans+=(lower_bound(a,a+n,b[i])-a)*(c+n-upper_bound(c,c+n,b[i]));
        }
        printf("%lld\n",ans);
    }
    system("pause");
	return 0;
}
