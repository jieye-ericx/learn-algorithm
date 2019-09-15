#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
//八皇后问题 
#define N 9
int x[N],ans;

bool canPut(int row,int col){
    int i;
    for(i=1;i<col;i++){
        if(x[i]==row || abs(row-x[i])==abs(col-i))
            return false;
    }
    return true;
}

void dfs(int dep){
    int i,j;
    if(dep>8){
        for(i=1;i<9;i++){
            for(j=1;j<9;j++){
                if(x[i]==j) cout<<"$ ";
                else cout<<"O ";
            }
            cout<<endl;
        }
        cout<<endl;
        ans++;
        return; 
    }
    for(i=1;i<9;i++){
        if(canPut(i,dep)){//i列dep行
            x[dep]=i;
            dfs(dep+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    dfs(1);
    cout<<ans<<endl;

    return 0;
}