/*
ÍÅ»ï
ÌâÄ¿ÃèÊö Description
1920ÄêµÄÖ¥¼Ó¸ç£¬³öÏÖÁËÒ»ÈºÇ¿µÁ¡£Èç¹ûÁ½¸öÇ¿µÁÓöÉÏÁË£¬ÄÇÃ´ËûÃÇÒªÃ´ÊÇÅóÓÑ£¬ÒªÃ´ÊÇµĞÈË¡£¶øÇÒÓĞÒ»µãÊÇ¿Ï¶¨µÄ£¬¾ÍÊÇ£º
ÎÒÅóÓÑµÄÅóÓÑÊÇÎÒµÄÅóÓÑ£»
ÎÒµĞÈËµÄµĞÈËÒ²ÊÇÎÒµÄÅóÓÑ¡£
Á½¸öÇ¿µÁÊÇÍ¬Ò»ÍÅ»ïµÄÌõ¼şÊÇµ±ÇÒ½öµ±ËûÃÇÊÇÅóÓÑ¡£ÏÖÔÚ¸øÄãÒ»Ğ©¹ØÓÚÇ¿µÁÃÇµÄĞÅÏ¢£¬ÎÊÄã×î¶àÓĞ¶àÉÙ¸öÇ¿µÁÍÅ»ï¡£
ÊäÈëÃèÊö Input Description
ÊäÈëÎÄ¼şgangs.inµÄµÚÒ»ĞĞÊÇÒ»¸öÕûÊıN(2<=N<=1000)£¬±íÊ¾Ç¿µÁµÄ¸öÊı£¨´Ó1±àºÅµ½N£©¡£ µÚ¶şĞĞM(1<=M<=5000)£¬±íÊ¾¹ØÓÚÇ¿µÁµÄĞÅÏ¢ÌõÊı¡£ ÒÔÏÂMĞĞ£¬Ã¿ĞĞ¿ÉÄÜÊÇF p q»òÊÇE p q£¨1<=p q<=N£©£¬F±íÊ¾pºÍqÊÇÅóÓÑ£¬E±íÊ¾pºÍqÊÇµĞÈË¡£ÊäÈëÊı¾İ±£Ö¤²»»á²úÉúĞÅÏ¢µÄÃ¬¶Ü¡£
Êä³öÃèÊö Output Description
Êä³öÎÄ¼şgangs.outÖ»ÓĞÒ»ĞĞ£¬±íÊ¾×î´ó¿ÉÄÜµÄÍÅ»ïÊı¡£
ÑùÀıÊäÈë Sample Input
6
4
E 1 4
F 3 5
F 4 6
E 1 2
ÑùÀıÊä³ö Sample Output
3
Êı¾İ·¶Î§¼°ÌáÊ¾ Data Size & Hint
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

//--------------------ç»“æ„ä½“å¹¶æŸ¥é›†---------------------------------------------------


struct node{
	int st;//Æğµã
	int ed;//ÖÕµã
	int rank;
	int rel;//0-friend 1-enemy Óë¸¸½ÚµãµÄ¹ØÏµ
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
///µİ¹é
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
    //-----------å°†ä¸€è·¯ä¸Šé‡åˆ°çš„çˆ¶èŠ‚ç‚¹éƒ½æ”¹ä¸ºæ ¹èŠ‚ç‚¹ï¼ˆkä¸ºæ ¹èŠ‚ç‚¹
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
/*/--------------------------------------æ•°ç»„å¹¶æŸ¥é›†--------------------------------------
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
    	if(find(x)!=find(y))//Á½¸ö¶Ëµã²»Á¬Í¨
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
