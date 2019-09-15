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
#define slld1(a) scanf("%lld",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pd1(a) printf("%d\n",a)
#define plld1(a) printf("%lld\n",a)
#define N 100005
int father[N],a[N];
int n,m,t,flag,i,cnt;
void setF(int x)
{
	for(int i=1; i<=x; i++)
		father[i]=i;
}

int find(int x)//查找
{
	if(x!=father[x])
		father[x]=find(father[x]);
	return father[x];
}

void Union(int a, int b)//合并
{
	int x=find(a);
	int y=find(b);
	if(x==y)
		flag=1;
	else
	    father[y]=x;
}

int main(){
setF(N);flag=0;
for(i=0;i<N;i++) a[i]=0;
while(sd2(n,m)){
    t++;
    if(n==-1&&m==-1){
        break;
    }
    if(n==0&&m==0){
        if(t==1) printf("Yes\n");
        if(flag) printf("No\n");
        else {
            cnt=0;
            for(i=0;i<N;i++){
                if(a[i]&&father[i]==i) cnt++;
            }
            if(cnt==1) printf("Yes\n");
            else printf("No\n");
        }
        flag=0;
        t=0;
        setF(N);
        for(i=0;i<N;i++) a[i]=0;
        continue;
    }
    Union(n,m);
    a[n]=1;a[m]=1;
}
return 0;
}

/*

#include <iostream>
#include <algorithm>
using namespace std;
const int M = 100005;
int a,b;
int father[M];       //记录父节点 
bool circle;         //判断是否存在环 
bool visit[M];       //用来记录顶点数  
int edgenum,vnum;    //分别表示边数，顶点数 
void initial( )
{
     for( int i=0 ; i<M ; i++ )
          father[i] = i,visit[i]=false;
     circle = false;  
     edgenum = vnum = 0;      
}
 
int find(  int x )
{
    return x == father[x] ? x : father[x] = find(father[x]);     //找祖先节点 + 路径压缩 
}
 
void merge( int a ,int b )
{
     if( a == b )
         circle = true;
     int x , y;
     x = find(a);
     y = find(b);
     if( x != y ){
         father[x] = y;
         edgenum++;       //引出一条边 
     }
     else
         circle = true;   //x==y，说明他们是同一个祖先，一旦连通便与祖先3者成环 
}
 
int main()
{
    while( true ){
           initial( );
           scanf("%d%d",&a,&b);
           if( a==0 && b==0 ){     //为空树 
               printf("Yes\n");       
               continue;
           }
           if( a==-1 && b==-1 )
               break;
           visit[a] = true;
           visit[b] = true;
           merge( a,b );
           while( true ){
                  scanf("%d%d",&a,&b);
                  if( a==0 && b==0 )
                      break;
                  visit[a] = true;
                  visit[b] = true;
                  merge( a , b );      
           }
           for( int i=0 ; i<M ; i++ )
                if( visit[i] )
                    vnum++;  
           if(  !circle && edgenum+1 == vnum )
               printf("Yes\n");
           else
               printf("No\n");
    }     
    return 0;
}


*/