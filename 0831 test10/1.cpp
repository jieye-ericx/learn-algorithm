/*
在讲述DP算法的时候，一个经典的例子就是数塔问题，它是这样描述的：
有如下所示的数塔，要求从顶层走到底层，若每一步只能走到相邻的结点，
则经过的结点的数字之和最大是多少？
已经告诉你了，这是个DP的题目，你能AC吗?
Input
输入数据首先包括一个整数C,表示测试实例的个数，
每个测试实例的第一行是一个整数N(1 <= N <= 100)，表示数塔的高度，
接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。
Output
对于每个测试实例，输出可能得到的最大和，每个实例的输出占一行。
Sample Input
1
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
Sample Output
30
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
int a[101][101],dp[101][101];
int main(){
    int i,t,j,n;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a[101]));
        memset(dp,0,sizeof(dp[101]));
        cin>>n;
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                cin>>a[i][j];
        dp[1][1]=a[1][1];
        for(i=2;i<=n;i++)
            for(j=1;j<=n;j++){
                dp[i][j]=a[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
            }
        int ret=0;
        for(i=0;i<=n;i++){
            if(dp[n][i]>ret){
                ret=dp[n][i];
            }
        }
        cout<<ret<<endl;
    }
    //system("pause");
    return 0;
}