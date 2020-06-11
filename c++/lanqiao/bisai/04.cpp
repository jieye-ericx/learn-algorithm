#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
using namespace std;
#define N 100007
char a[N];
int vis[N];
int ans[N];
int i,j,k;
int main(){
    ios::sync_with_stdio(false);
    //
    while(scanf("%s",a)){
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));

        for(i=0;a[i]!='\0';i++){
            if(a[i]==')'){
                for(j=i-1;j>=0;j--){
                    if(vis[j]) continue;
                    if(a[j]=='('&&vis[j]==0){
                        ans[j]=i;
                        vis[j]=1;
                        break;
                    }
                }
            }
        }
        for(k=0;k<i;k++){
            if(a[k]=='('){
                cout<<k+1<<' '<<ans[k]+1<<endl;
            }
        }
        //cout<<i<<endl;
        //cout<<sizeof(a);
        // cout<<a;
        // if(a[10000]=='\0')cout<<1;
    }

    system("pause");
    return 0;
}