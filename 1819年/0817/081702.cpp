
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
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define p(a) printf("%d\n",a)
#define N 1005
int n,m,u,v;
int edge[N][2];
//---------------------------------------------------------------------
struct node{
    int data;
    int paraent;
    int rank;
}uf[N];


int find(int x){
    int k=x,k1;
    while(k!=uf[k].paraent){
        x=uf[k].paraent;
    }
    //-----------将一路上遇到的父节点都改为根节点（k为根节点
    while(x!=uf[x].paraent){
        k1=uf[x].paraent;
        uf[x].paraent=k;
        x=k1;
    }
    return k;
}

int Union(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        if(uf[x].rank < uf[y].rank){
        uf[x].paraent=y;
        }else{
            uf[y].paraent=x;
            if(uf[x].rank==uf[y].rank){
                uf[x].rank++;
            }
        }
        return 0;
    }
    return 1;
}
/*/--------------------------------------数组并查集--------------------------------------
int data[N],rank[N],paraent[N];

int find(int x){
    if(x==paraent[x])
        return x;
    return find(paraent[x]);
}
*///-------------------------------------------------------------------------------------

void ini(){
	int i;
	for(i=1;i<=n;i++){
		uf[i].paraent=i;
	}
}

int main(){
    int i,j,x,y,ans;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        uf[i].paraent=i;
    }
    for(i=0;i<m;i++){
        cin>>x>>y;
        edge[i][0]=x;
        edge[i][1]=y;
        Union(x,y);
    }
    cin>>u>>v;
    if(find(u)!=find(v)){
		cout<<-1<<endl;
    return 0;
	}
	for(i=1;i<=n;i++){
		if(i==u||i==v){
			continue;
		}
		for(j=0;j<m;j++){
			if(edge[j][0]!=i && edge[j][1]!=i){
				Union(edge[j][0],edge[j][1]);
			}
		}
		if(find(u)!=find(v))
			ans++;

	}
	p(ans);
	
}
