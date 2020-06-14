#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;


int ans,n,i,j,s,m;
//int prime[40]={0,1,1,1,0,1, 0,1,0,0,0, 1,0,1,0,0, 0,1,0,1,0, 0,0,1,0,0, 0,0,0,1,0, 1,0,0,0,0,0,1, 0,1};

void dfs(int dep,int b0,int b1,int b2){
    if(dep>7) return;
    if(b1>n||b2>m||b0>s||b1<0||b2<0||b0<0) return;
    if((b0==b1&&b2==0)||(b0==b2&&b1==0)||(b1==b2&&b0==0)) {
        ans=min(ans,dep);
        return;
    }
    if(b1!=n){
        dfs(dep+1,b0-(n-b1),n,b2);
        dfs(dep+1,b0,n,b2-(n-b1));
    }
        

    if(b2!=m){
        dfs(dep+1,b0-(m-b2),b1,m);
        dfs(dep+1,b0,b1-(m-b2),m);
    }
    dfs(dep+1,b0+b1,0,b2);
    dfs(dep+1,b0+b2,b1,0);

}

int main(){
    ios::sync_with_stdio(false);
    while(scanf("%d%d%d",&s,&n,&m)!=EOF,s){
        ans=10000000;
        //
        if(n==m){
            printf("1\n");
            continue;
        }
        // if(s&1){
        //     printf("NO\n");
        //     continue;
        // } 
        dfs(0,s,0,0);
        if(ans!=10000000) cout<<ans<<endl;
        else cout<<"NO"<<endl;
    }

    system("pause");
	return 0;
}
