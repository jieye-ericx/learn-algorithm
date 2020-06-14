#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 15005;
const int M = 32005;
int n,x,y,i,j;
int level[N];
int c[M];
int lowbit(int x){
    return x&(-x);
}

void add(int x,int y){
    while(x<=M) {
        c[x]+=y;
        x+=lowbit(x);
    }
}

int getSum(int x)
{
    int ans = 0;
    while(x>0) {
		ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(level,0,sizeof(level));
		memset(c,0,sizeof(c));
		
		//
		for(i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x+1,1);
			level[getSum(x+1)-1]++;//¼ÇÂ¼µÈ¼¶
		}
		for(i=0;i<n;i++){
			printf("%d\n",level[i]);
		}//printf("%d",level[n-1]);
	}
	return 0;
}
