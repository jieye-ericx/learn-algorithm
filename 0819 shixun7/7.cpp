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
#define MAX 550
//存储11中类型的土地，二维中的0 1 2 3分别代表这种类型的土地的左上右下
//为1表示这个方向有接口，为0表示这个方向没有接口
const int type[12][4]={{0,0,0,0},{1,1,0,0},{0,1,1,0},
						{1,0,0,1},{0,0,1,1},
						{0,1,0,1},{1,0,1,0},
						{1,1,1,0},{1,1,0,1},
						{1,0,1,1},{0,1,1,1},
						{1,1,1,1}
						};
int n,m,i,j,num,cnt;
int a[55][55],f[2504],vis[55][55];
char s;
// int find(int t){
// 	int x=t;
// 	while(x!=f[x]){
// 		x=f[x];
// 	}
// 	//根节点为x
// 	int y;
// 	while(t!=f[t]){
// 		y=f[t];
// 		f[t]=x;
// 		t=y;
// 	}
// 	return x;
// }

// void unite(int x,int y){
// 	if(x<1||y<1||x>m||y>n) return;
// 	if(find(x)<find(y)){
// 		f[find(y)]=find(x);
// 	}else{
// 		f[find(x)]=find(y);
// 	}
// 	return;
// }
bool ch(int i,int j){
		if(i<1||j<1||i>m||j>n) return false;
		return true;
}

void dfs(int i,int j){
	if(i<1||j<1||i>m||j>n) return;
	if(vis[i][j]) return;
	vis[i][j]=cnt;

	for(int k=0;k<4;k++){
		if(type[a[i][j]][k]==1){
			if(k==0) {
				if(ch(i,j-1))
				if(type[a[i][j-1]][2]==1){
					dfs(i,j-1);
				}
			}
			else if(k==1) {
				if(ch(i-1,j))
				if(type[a[i-1][j]][3]==1){
					dfs(i-1,j);
				}
			}
			else if(k==2) {
				if(ch(i,j+1))
				if(type[a[i][j+1]][0]==1){
					dfs(i,j+1);
				}
			}
			else {
				if(ch(i+1,j))
				if(type[a[i+1][j]][1]==1){
					dfs(i+1,j);
				}
			}
		}
	}

	return;
}

int main(){
	while(scanf("%d%d",&m,&n)!=EOF,m>0){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=m*n;i++){
			f[i]=i;
		}
		num=0;
		cnt=0;;
		//
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				cin>>s;
				a[i][j]=s-'A'+1;
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				//for(k=0;k<4;k++){
					if(!vis[i][j]){
						cnt++;
						dfs(i,j);
						
					}
				//}
			}
		}
		
		cout<<cnt<<endl;
	}
    system("pause");
    return 0;
}