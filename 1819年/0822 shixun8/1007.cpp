#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
//#include <windows.h>
using namespace std;
//八皇后问题 
#define N 8
int x[N],ans,n,p[N];
int i;

bool canPut(int row,int col){//row表示列col表示行
    int i;
    for(i=1;i<col;i++){
        if(x[i]==row || abs(row-x[i])==abs(col-i))
            return false;
    }
    return true;
}

void dfs(int dep){
    int i,j;
    if(dep>n){
        ans++;
        for(int i=1;i<=n;i++){
            for(int y=1;y<=n;y++){
                if(y!=x[i]) cout<<"O";
                else cout<<"X";
            }
            cout<<endl;
        }cout<<endl;
        return; 
    }
    for(i=1;i<=n;i++){
        if(canPut(i,dep)){//i列dep行
            x[dep]=i;
            dfs(dep+1);
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    for(n=1;n<N;n++){
        dfs(1);
        p[n]=ans;
        ans=0;
    }
    while(~scanf("%d",&n)&&n){
        printf("%d\n",p[n]);
    }
    //system("pause");
    return 0;
}