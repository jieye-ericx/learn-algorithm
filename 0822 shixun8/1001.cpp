#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
//#include<Windows.h>
#include<map>
using namespace std;
#define M 42000000
long long prime[M],check[M];
int cnt,tot=0,i,j,n;long long g;
void olgprime(){
    int i,j;
    for(i=2;i<M;i++){
        if(!check[i]){
            prime[tot++]=i;
        }
        for(j=0;j<tot;j++){
            if(prime[j]*i>=M) break;
            check[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
        
    }
}
int main(){

    olgprime();
    while(~scanf("%d",&n)){
        cnt=0;
        for(i=0;i<n;i++){
            scanf("%lld",&g);
            if(upper_bound(prime,prime+tot,g)-lower_bound(prime,prime+tot,g)==1)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    
    //system("pause");
    return 0;
}

/*
#include<stdio.h>
#include<math.h>
int is_prime(int x)
{
	int tp=(int)sqrt(x*1.0);
	for(int i=2;i<=tp;++i)
	{
		if(x%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int ans=0,tp;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&tp);
			if(tp==2)
			{
				++ans;
			}
			else if(tp&1)
			{
				ans+=is_prime(tp);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

*/