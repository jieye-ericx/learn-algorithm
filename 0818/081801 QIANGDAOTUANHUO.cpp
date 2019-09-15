/*
�Ż�
��Ŀ���� Description
1920���֥�Ӹ磬������һȺǿ�����������ǿ�������ˣ���ô����Ҫô�����ѣ�Ҫô�ǵ��ˡ�������һ���ǿ϶��ģ����ǣ�
�����ѵ��������ҵ����ѣ�
�ҵ��˵ĵ���Ҳ���ҵ����ѡ�
����ǿ����ͬһ�Ż�������ǵ��ҽ������������ѡ����ڸ���һЩ����ǿ���ǵ���Ϣ����������ж��ٸ�ǿ���Ż
�������� Input Description
�����ļ�gangs.in�ĵ�һ����һ������N(2<=N<=1000)����ʾǿ���ĸ�������1��ŵ�N���� �ڶ���M(1<=M<=5000)����ʾ����ǿ������Ϣ������ ����M�У�ÿ�п�����F p q����E p q��1<=p q<=N����F��ʾp��q�����ѣ�E��ʾp��q�ǵ��ˡ��������ݱ�֤���������Ϣ��ì�ܡ�
������� Output Description
����ļ�gangs.outֻ��һ�У���ʾ�����ܵ��Ż�����
�������� Sample Input
6
4
E 1 4
F 3 5
F 4 6
E 1 2
������� Sample Output
3
���ݷ�Χ����ʾ Data Size & Hint
2<=N<=1000
1<=M<=5000
1<=p q<=N
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
using namespace std;
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define p(a) printf("%d\n",a)
#define N 505

//--------------------结构体并查集---------------------------------------------------


struct node{
	int st;//���
	int ed;//�յ�
	int rank;
	int rel;//0-friend 1-enemy �븸�ڵ�Ĺ�ϵ
	int parent;
	node():rel(0),rank(1){
	}

	
}uf[N];

int find(int x){
    if(x==uf[x].parent)
        return x;
	int pa=uf[x].parent;
    uf[x].parent=find(uf[x].parent);
    uf[x].rel=uf[x].rel^uf[uf[x].parent].rel;
    return find(uf[x].parent);
///�ݹ�
}
int find1(int x){
    int k=x,k1,idx[N],cnt=0;
    while(k!=uf[k].parent){
    	idx[cnt++]=k;
        k=uf[k].parent;
    }
    int i;
    for(i=cnt-2;i>=0;i++){
    	uf[idx[i]].rel=uf[idx[i]].rel^uf[idx[i-1]].rel;
    	uf[idx[i]].parent=k;
	}
    //-----------将一路上遇到的父节点都改为根节点（k为根节点
    /*while(x!=uf[x].parent){
        k1=uf[x].parent;
        
        uf[x].parent=k;
        x=k1;
    }*/
    return k;
}

int Union(int u,int v,int r){
	int x,y;
	x=find(u);
    y=find(v);
    if(x!=y){
        if(uf[x].rank < uf[y].rank){
        uf[x].parent=y;
        uf[x].rel=r^uf[u].rel^uf[v].rel;
        }else{
            uf[y].parent=x;
            uf[y].rel=r^uf[u].rel^uf[v].rel;
            if(uf[x].rank==uf[y].rank){
                uf[x].rank++;
            }
        }
        return 0;
    }
    return 1;
}
/*/--------------------------------------数组并查集--------------------------------------
int data[N],rank[N],parent[N];

int find(int x){
    if(x==parent[x])
        return x;
    return find(parent[x]);
}
*///-------------------------------------------------------------------------------------

int n,m,p;
int main(){
    int i,x,y,t,ans,t1;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        uf[i].parent=i;
    }
    for(i=0;i<m;i++){
        cin>>edge[i].st>>edge[i].ed>>edge[i].time;
    }
    sort(edge,edge+m);
    t1=-1;
    for(i=o;i<m;i++){
    	x=edge[i].st;y=edge[i].ed;t=edge[i].time;
    	if(find(x)!=find(y))//�����˵㲻��ͨ
		{
			if(t!=t1){
				ans++;
				t1=t;
			}
            Union(x,y);
		}

	}
    return 0;
}
