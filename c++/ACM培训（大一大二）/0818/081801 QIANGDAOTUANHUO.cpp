/*
团伙
题目描述 Description
1920年的芝加哥，出现了一群强盗。如果两个强盗遇上了，那么他们要么是朋友，要么是敌人。而且有一点是肯定的，就是：
我朋友的朋友是我的朋友；
我敌人的敌人也是我的朋友。
两个强盗是同一团伙的条件是当且仅当他们是朋友。现在给你一些关于强盗们的信息，问你最多有多少个强盗团伙。
输入描述 Input Description
输入文件gangs.in的第一行是一个整数N(2<=N<=1000)，表示强盗的个数（从1编号到N）。 第二行M(1<=M<=5000)，表示关于强盗的信息条数。 以下M行，每行可能是F p q或是E p q（1<=p q<=N），F表示p和q是朋友，E表示p和q是敌人。输入数据保证不会产生信息的矛盾。
输出描述 Output Description
输出文件gangs.out只有一行，表示最大可能的团伙数。
样例输入 Sample Input
6
4
E 1 4
F 3 5
F 4 6
E 1 2
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
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

//--------------------缁撴瀯浣撳苟鏌ラ泦---------------------------------------------------


struct node{
	int st;//起点
	int ed;//终点
	int rank;
	int rel;//0-friend 1-enemy 与父节点的关系
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
///递归
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
    //-----------灏嗕竴璺笂閬囧埌鐨勭埗鑺傜偣閮芥敼涓烘牴鑺傜偣锛坘涓烘牴鑺傜偣
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
/*/--------------------------------------鏁扮粍骞舵煡闆�--------------------------------------
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
    	if(find(x)!=find(y))//两个端点不连通
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
