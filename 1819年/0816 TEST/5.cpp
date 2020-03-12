#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;
#define N 1000005
long long a[N]={0};
int i,j,n,t,sum,m;
//int main(){
int main(){
    

    scanf("%d",&t);
    while(t--){
        sum=0;
        scanf("%d",&n);
        for(i=n;i<n+10;i++){
        	a[i]=0;
		}
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);m=1;
		for(i=0;i<n-1;i++){
        	m=1;
            for(j=0;j<32;j++){
				m=(1<<j)-a[i];
				if(m<=0) {continue;}
				if(m>a[n-1]) break;
            	sum+=upper_bound(a+i+1,a+n,m)-lower_bound(a+i+1,a+n,m);
            }
        }
        printf("%d\n",sum);
        
    }
    return 0;
}
