#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100008
struct node{
    int x,y;
} p[N];
int dis[10000000];
int n,i,t,m,j,dt,flag;
int main(){
    scanf("%d",&t);
	while(t--){
        memset(p,0,sizeof(p));
        memset(dis,0,sizeof(dis));
        flag=0;
        //
		scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                dt=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
                if(dis[dt]) {
                    flag=1;
                    break;
                }
                dis[dt]=1;
            }
            if(flag) break;
        }
        
        if(flag){
            printf("YES\n");
        }else {
            printf("NO\n");
        }
	}
    system("pause");
	return 0;
}
