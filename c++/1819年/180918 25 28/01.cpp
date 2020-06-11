#include <iostream>
#include <string>

using namespace std;
#define N 100000
string a,b;
int f[N][N];
char x[N];
int cnt;
int n,m;
void dfs(int i,int j){
    if(i==0||j==0){
        for(int k=0;k<cnt;k++){
            cout<<x[k]<<" ";
        }
        cout<<endl;
        return;
    }
    if(a[i]==b[j]){
        x[cnt++]=a[i];
        dfs(i-1,j-1);
        cnt--;
    }else{
        if(f[i-1][j]>f[i][j-1])
            dfs(i-1,j);
        else if(f[i-1][j]<f[i][j-1])
        {
            dfs(i,j-1);
        }else{
            dfs(i,j-1);
            dfs(i-1,j);
        }
    }
}

int main(){
    cin>>a>>b;
    dfs(a.length(),b.length());
    system("pause");
    return 0;
}