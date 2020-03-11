#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int a[4],b,t,cnt=0;
int main(){
    while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])!=EOF&&!(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)){
        if(cnt!=0) printf("\n");
        cnt++;
        sort(a,a+4);
        b=a[0];
        // next_permutation(a,a+4);
        if(a[0]) printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
        if(!b) t=0;
        else t=1;
		while(next_permutation(a,a+4)){
            if(!a[0]) continue;
            if(b!=a[0]){
                b=a[0];
                if(t++) printf("\n");
            }else if(b) printf(" ");
            printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
        }
        printf("\n");
	}
    system("pause");
	return 0;
}
