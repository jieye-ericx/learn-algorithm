
#include <cstdio>
#define sd1(a) scanf("%d",&a)
#define slld1(a) scanf("%lld",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pd1(a) printf("%d\n",a)
#define plld1(a) printf("%lld\n",a)
#define N 1005
int n,m,t,r1,r2,i,sum;

struct node{
    int parent;
}uf[N];
/*int find(int x){
    int k1=x,k2=x,t;
    while(k1!=uf[k1].parent){
        k1=uf[k1].parent;
    }
    while(k2!=uf[k2].parent){
        t=uf[k2].parent;
        uf[k2].parent=k1;
        k2=t;
    }
    return x;
}*/
int find(int x)//查找
{
	if(x!=uf[x].parent)
		uf[x].parent=find(uf[x].parent);//回溯，路径压缩
	return x;
}

void set(int n){
    for(i=0;i<n;i++){
            uf[i].parent=i;
        }
}

void Union(int a, int b)//合并
{
	int x=find(a);
	int y=find(b);
	if(x==y)
		return;
	sum=sum-1;
	uf[x].parent=y;
}

int main(){
    sd1(t);
    while(t--){
        
        sd2(n,m);
        sum=n;
        set(n);
        for(i=0;i<m;i++){
            sd2(r1,r2);
            Union(r1,r2);
            
        }
        
        pd1(sum);
        
    }
    return 0;
}

/*
#include <iostream>
#include <stdio.h>
using namespace std;
 
int sum, n, m;
int father[1000];
 
void makeset(int x)
{
	for(int i=1; i<=x; i++)
		father[i]=i;
}
 
int findset(int x)//查找
{
	if(x!=father[x])
		father[x]=findset(father[x]);//回溯，路径压缩
	return father[x];
}
 
void Union(int a, int b)//合并
{
	int x=findset(a);
	int y=findset(b);
	if(x==y)
		return;
	sum=sum-1;
	father[y]=x;
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for(int j=1; j<=t; j++)
	{
		scanf("%d%d", &n, &m);
		sum=n;
		makeset(n);
		int first, second;
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d", &first, &second);
			Union(first, second);
		}
		printf("%d\n", sum);
		getchar();
	}
	return 0;
 
}
*/