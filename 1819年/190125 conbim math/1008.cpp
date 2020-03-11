#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
#define N 70
int t,n,k,a,b,i,m,j;
int score[N];
int c1[N],c2[N];

int main(){
    scanf("%d",&t);
    while(t--){//不加EOF会超时！！
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        memset(score,0,sizeof(score));
        //
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            score[a]=b;
        }
        c1[0]=1;
        for(i=1;i<=m;i++){
            for(j=0;j<=n;j++){
                for(k=0;k<=score[i]&&j+k*i<=n;k++){
                    c2[j+k*i]+=c1[j];
                }
            }
            for(j=0;j<=n;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[n]);   
	}
    system("pause");
	return 0;
}

