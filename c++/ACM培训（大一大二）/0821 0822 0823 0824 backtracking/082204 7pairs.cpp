/*
题目：今有7对数字：两个1，两个2，两个3，…两个7，把它们排成一行。 
要求：两个1间有1个其它数字，两个2间有2个其它数字，以此类推，两个7之间有7个其它数字。
如下就是一个符合要求的排列：17126425374635。 
当然，如果把它倒过来，也是符合要求的。 
请你找出另一种符合要求的排列法，并且这个排列法是以74开头的。 
注意：只填写这个14位的整数，不能填写任何多余的内容，比如说明注释等（可不用编程直接算出答案）。

总结解题思路：           0 1 2 3 4 5 6 7 8 9 10 11 12 13
由题目要求可知要填的数为：7 4 _ _ _ _ 4 _ 7 _  _  _  _  _ 
*/
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
#include<Windows.h>
#include<map>
using namespace std;
#define N 14
int a[N]={1,1,2,2,3,3,4,4,5,5,6,6,7,7},x[N],v[N/2+1]={0};

/*nt dfs(int dep){
    int i,j,flag=0;
    if(dep>=N){
        for(i=0;i<N;i++){
            cout<<x[i];
        }
        cout<<endl;
        return;
    }
    for(i=2;i<N;i++){
        if(!v[i]){
            for(j=0;j<N;j++){
                if(i==j+x[j]+1){
                    x[i]=x[j];
                    v[2*x[j]-1]=1;
                    flag=1;
                    break;
                }
            }
            if(flag) dfs(dep+1);
            else {
                x[i]=a[i];
                v[i]=1;
                dfs(dep+1);
                v[i]=0;
            }
        }
    }
}*/

void dfs(int cur,int dep){
    int i,j;
    if(dep>4){
        for(i=0;i<N;i++){
            cout<<x[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(i=1;i<=7;i++){
        if(v[i]==0&&x[cur+i+1]==0&&cur+i+1<14){
            x[cur]=i;
            x[cur+i+1]=i;
            v[i]=1;
            for(j=2;j<14;j++){
                if(x[j]==0){
                    break;
                }
            }
            dfs(j,dep+1);
            v[i]=0;
            x[cur]=x[cur+i+1]=0;
        }
    }
}

int main(){
    x[0]=x[8]=7;
    v[7]=1;v[4]=1;
    x[1]=x[6]=4;   
    dfs(2,0);
    system("pause");
    return 0;
}