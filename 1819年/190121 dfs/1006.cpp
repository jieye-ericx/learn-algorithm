#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 10
int vis[N][N];
char a[N][N];
int n,i,j;
//int prime[40]={0,1,1,1,0,1, 0,1,0,0,0, 1,0,1,0,0, 0,1,0,1,0, 0,0,1,0,0, 0,0,0,1,0, 1,0,0,0,0,0,1, 0,1};


int main(){
    ios::sync_with_stdio(false);
    while(scanf("%s",a)!=EOF){
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                cout<<a[i][j];
            }
        }
    }
	return 0;
}
