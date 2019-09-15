#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100003
int i,j,k,n,x,y;
long long int dis[N],cur;
int dir,cnt;
int main(){
    cnt=0;dir=-1;//0表示向左，1表示向上，2表示向右，3表示向下
    memset(dis,0,sizeof(dis));
    cur=0;
    x=0;y=0;
    for(i=0;i<100004;i++){
        cnt++;
        for(j=0;j<2;j++){
            dir=(dir+1)%4;
            cur+=cnt;
            switch (dir)
            {
                case 0:
                    x-=cnt;
                    break;
                case 1:
                    y+=cnt;
                    break;
                case 2:
                    x+=cnt;
                    break;
                case 3:
                    y-=cnt;
                    break;
            }
            if(x==y&&x>0) dis[x]=cur;
        }
    }
    while(cin>>x>>y){
        cur=dis[max(x,y)];
        if(x>0&&y>0)
    }
    
    
    system("pause");
	return 0;
}
