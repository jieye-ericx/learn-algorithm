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
string a,b,c;
int n,i,x,y,k;
int dp[203][203];

int main(){
    scanf("%d",&n);
    for(k=1;k<=n;k++){
        memset(dp,0,sizeof(dp));
        //
        cin>>a>>b>>c;
        if(a==c||b==c) {
            printf("Data set %d:yes\n",k);
            continue;
        }
        for(x=1;x<=a.length();x++){
            for(y=1;y<=b.length();y++){
                if( (dp[x-1][y]&&a[x-1]==c[x+y-1])||(dp[x][y-1]||b[y-1]==c[x+y-1])){
                    dp[x][y]=1;
                }
            }
        }

        if(dp[a.length()][b.length()]) 
        printf("Data set %d:yes\n",k);
        else
        printf("Data set %d:no\n",k);
    }
    system("pause"); 
        return 0;
}