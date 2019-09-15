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
#define N 14
int a[N][N];
int n,m,i,j,x,y;
int main(){
	memset(a,0,sizeof(a));
	//ios::sync_with_stdio(false);
	scanf("%d%d",&n,&m);
	for(x=1;x<=n;x++){
		for(y=1;y<=m;y++){
			for(i=1;i*x<=n;i++){
				for(j=1;j<=m;j++){
					a[i*x][j]=(a[i*x][j]+1)%2;
				}
			}
			for(i=1;i*y<=m;i++){
				for(j=1;j<=n;j++){
					a[j][i*y]=(a[j][i*y]+1)%2;
				}
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}


