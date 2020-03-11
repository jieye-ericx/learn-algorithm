#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1<<30;
int n,i,t,j,c,e,V[16],E[16];



int main(){
	ios::sync_with_stdio(false);
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&n,&e);
        for(i=1;i<=n;i++){
            scanf("%d",&V[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&E[i]);
        }
    }
    system("pause");
	return 0;
}
