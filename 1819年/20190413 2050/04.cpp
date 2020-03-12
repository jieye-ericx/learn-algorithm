#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
int n,m,k,t;
int a,b[14],c[14];
long long sum;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        sum=0;
        // memset(b,0,sizeof(b));

        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            //scanf("%d",&a);
            cin>>a;
            b[a]++;
            if(i==n/2){
                for(int j=1;j<=m;j++){
                    c[j]=b[j];
                }
            }
        }
        for(int i=1;i<=m;i++){
            b[i]/=k;
            if(c[i]<=b[i]) sum+=c[i];
            else sum+=b[i];
        }
        cout<<sum<<"\n";
        // printf("%lld\n",sum);

    }
    // system("pause");
    return 0;
}