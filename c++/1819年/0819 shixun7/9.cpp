#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
//#include <Windows.h>
using namespace std;
#define N 2005

int father[N],fri[N];
int t,j,n,m,i,ans1,ans2,temp;

int findset(int x){
	if(x!=father[x])
		{
            int r=findset(father[x]);
            fri[x]=(fri[x]+fri[father[x]])%2;
            father[x]=r;
            return r;
        }
	return father[x];
}
void unit(int x,int y){
    int xl=findset(x);
    int yl=findset(y);
    if(xl!=yl){
        father[xl]=yl;
        fri[xl]=(fri[y]+1-fri[x]+2)%2;
    }else{
        if((fri[x]-fri[y]+2)%2==0) temp=1;
    }
}
int main(){
    char name1[30],name2[30];
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        for(i=0;i<N;i++){
        father[i]=i;
        fri[i]=0;
        }
        temp=0;
        /////////////
        scanf("%d",&n);
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d",&ans1,&ans2);
            unit(ans1,ans2);
        }
        printf("Scenario #%d:\n",j);  
        if(temp) printf("Suspicious bugs found!\n\n");
        else printf("No suspicious bugs found!\n\n"); 
    }
    //system("pause");
    return 0;   
}