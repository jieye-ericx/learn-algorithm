#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define N 1003
int n,s,i,j,k,cnt0,cnt;
double a[N],b[N],sum,mon,cur,ans;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>s){
        memset(a,0,sizeof(a)); 
        memset(b,0,sizeof(b));

        for(i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        
        sort(a,a+n,greater<int>());
        sort(b,b+n,greater<int>());
        mon=s/n;
        if(mon<=a[n-1]){
            cout<<"0.0000"<<"\n";
            continue;
        }
        cnt=n,cnt0=n,cur=0;
        while(abs(cur-(double)s)>0.0000001){
            cnt=cnt0;
            mon=((double)s-cur)/cnt;
            for(i=0;i<cnt;i++){
                if(a[i]>mon){
                    cur+=mon;
                    a[i]-=mon;
                }
                else{
                    cur+=a[i];
                    a[i]=0;
                    cnt0--;
                }
            }
        }
        for(i=0;i<n;i++){
            a[i]=b[i]-a[i];
        }
        // for(i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        for(i=0;i<n;i++){
            ans=ans+a[i]*a[i];
        }
        ans/=n;
        ans=ans-(s*s)/(n*n);
        printf("%.4lf\n",sqrt(ans));
    }
    
    system("pause");
	return 0;
}
