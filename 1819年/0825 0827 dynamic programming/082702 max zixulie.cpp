/*
    例如：X="abcdefghi" Z="xyazdwf"
    用f(i,j)表示X的前i个与Z的前j个元素的最长公共子串
*/
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
#define N 1003

char x[N],y[N];
int dp[N][N];

int main(){

    int i,j,lenx,leny;
    cin>>x+1>>y+1;
    x[0]=y[0]='a';
    lenx=strlen(x),leny=strlen(y);

    for(i=0;i<lenx;i++){
        dp[i][0]=0;
    }
    for(i=0;i<leny;i++){
        dp[0][i]=0;
    }
    for(i=1;i<lenx;i++){
        for(j=1;j<leny;j++){
        if(x[i]==y[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[lenx-1][leny-1]<<endl;
    system("pause");
    return 0;
}
//以上为全数组储存，以下为滚动数组
/*
    例如：X="abcdefghi" Z="xyazdwf"
    用f(i,j)表示X的前i个与Z的前j个元素的最长公共子串
*/
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
#define N 1003

char x[N],y[N];
//int dp[N][N];
int pre[N],cur[N];
int main(){

    int i,j,lenx,leny;
    cin>>x+1>>y+1;
    x[0]=y[0]='a';
    lenx=strlen(x),leny=strlen(y);

    for(i=0;i<lenx;i++){
        pre[i]=0;
    }
    //for(i=0;i<leny;i++){
    //    dp[0][i]=0;
    //}
    for(i=1;i<lenx;i++){
        cur[i]=0;
        for(j=1;j<leny;j++){
            if(x[i]==y[j]) 
            cur[j]=pre[j-1]+1;
            //dp[i][j]=dp[i-1][j-1]+1;
            else 
            cur[j]=max(cur[j-1],pre[j]);
            //dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        for(j=0;j<leny;j++)
            pre[j]=cur[j];
        //这里拷贝也可以用memcpy(pre,cur,leny);
    }
    cout<<cur[leny-1]<<endl;
    //cout<<dp[lenx-1][leny-1]<<endl;
    system("pause");
    return 0;
}