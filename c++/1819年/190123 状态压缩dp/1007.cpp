#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 50005
long long int c[N],b[N],num1[N],num2[N];
int n,t,i,j;
long long int ans,ans1,ans2;

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
    scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        //
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            scanf("%d",&b[j]);
        }
        for(j=1;j<=n;j++){
            add(b[j],1);
            num1[j]=getSum(b[j]-1);//记录前j-1各数中比b[j]小的
        }
        memset(c,0,sizeof(c));

        for(j=n;j>0;j--){
            add(b[j],1);
            num2[j]=n-j-getSum(b[j]-1);
            num2[j]+=num2[j+1];
        }
        for(j=1;j<=n;j++){
            cout<<num1[j]<<" ";
        }cout<<endl;
        // for(j=1;j<=n;j++){
        //     cout<<num3[j]<<" ";
        // }cout<<endl;
        for(j=1;j<=n;j++){
            cout<<num2[j]<<" ";
        }
        ans=0;
        for(j=2;j<n-1;j++){
            ans+=num1[j]*num2[j+1];
        }
        printf("%lld\n",ans);
	}
    system("pause");
	return 0;
}
