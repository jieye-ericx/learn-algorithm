#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1000008
int a[N];
int n,i,t;
long long int sum;
int main(){
    scanf("%d",&t);
	while(t--){
        sum=0;
        memset(a,0,sizeof(a));
		scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a,a+n);
        sum-=a[n-1];
        sum++;
        if(sum>=a[n-1]){
            printf("Yes\n");
        }else {
            printf("No\n");
        }
	}
    system("pause");
	return 0;
}
