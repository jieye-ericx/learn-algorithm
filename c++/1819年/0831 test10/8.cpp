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


string str1,str2;
int len1,len2;
int dp[1005][1005];
int i,j;

int main(){

    while(cin>>str1>>str2){
        len1=str1.length();
        len2=str2.length();
        //
        memset(dp,0,sizeof(dp));
        //
        
        

        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        cout<<dp[len1][len2]<<endl;
    }
    system("pause");
    return 0;
}