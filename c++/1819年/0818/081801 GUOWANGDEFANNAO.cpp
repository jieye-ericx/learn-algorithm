/*
    并查集 Disjoint Set
    father[x]=y x的父节点是y
*/
/*
Description
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。
Input
第一行：三个整数n,m,p，（n< =5000,m< =5000,p< =5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数Mi，Mj，1< =Mi，Mj< =N，表示Mi和Mj具有亲戚关系。 接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
Output
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关
Yes
Yes
No
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
	int time;
	
	bool operator < (const node &n1) const{
		return time>n1.time;
	}
}edge[N];

/*int find(int x){
    if(x==uf[x].paraent)
        return x;
    uf[x].paraent=find(uf[x].paraent);
    return find(uf[x].paraent);
}*///递归可能会超时越栈，用下面的方法

int find(int x){
    int k=x,k1;
    while(k!=uf[k].paraent){
        k=uf[k].paraent;
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

int n,m,p;
int main(){
    int i,x,y;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        uf[i].paraent=i;
    }
    for(i=0;i<m;i++){
        cin>>edge[i].st>>edge[i].ed>>edge[i].time;
    }
    sort(edge,edge+m);
    for(i=o;i<m;i++){
    	x=edge[i].st,y=edge[i].ed;
    	if(find(x)!=find(y))//�����˵㲻��ͨ
		{
            ans++;
            Union(x,y);
		}
			
	}
    return 0;
}
