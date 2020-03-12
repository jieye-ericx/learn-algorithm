#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
//#include <Windows.h>
using namespace std;
#define N 50005
int father[N],loc[N];
int n,m,a,b,p;
int i,j,cnt,maxm,minm;

int findset(int x){
	if(x==father[x]) return father[x];
    int t=father[x];
    father[x]=findset(father[x]);//回溯，路径压缩
    loc[x]+=loc[t];    
    return father[x];
}
bool unit(int x,int y){
    int xl=findset(x);
    int yl=findset(y);
    if(xl==yl){
        if(abs(loc[x]-loc[y])!=p) return false;
        //if(loc[x]+p!=loc[y]) return false;
        return true;
    }else{
        father[yl]=xl;
        loc[yl]=loc[x]+p-loc[y];
        return true;
    }
    
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        
        for(i=0;i<n;i++){
            father[i]=i;
            loc[i]=0;
        }
        cnt=0;
        ////////////////
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&p);
            //if(!loc[i])loc[i]=p;
            
            if(!unit(a,b)) cnt++;
        }
        printf("%d\n",cnt);
    }
    //system("pause");
    return 0;
}