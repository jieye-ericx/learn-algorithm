#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300005;

int n,m,k;
int C[N],a[N];

struct note{
    int x,id;
    bool operator <(const note &other)const{
        return x<other.x;
    }
}p[N];

int lowbit(int i){
    return i&(-i);
}

int getsum(int x){
    int cnt=0;
    while(x>0){
        cnt+=C[x];
        x-=lowbit(x);
    }
    return cnt;
}

void add(int pos,int value){
    while(pos<=k){
        C[pos]+=value;
        pos+=lowbit(pos);
    }
}
int main()
{
    int T,tt=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int nn=n*2;
        int mm=nn+m;
        for(int i=0;i<mm;i++){
            scanf("%d",&p[i].x);
            p[i].id=i;
        }
        sort(p,p+mm);
        k=1;
        a[p[0].id]=k;
        for(int i=1;i<mm;i++){
            if(p[i].x==p[i-1].x)a[p[i].id]=k;
            else a[p[i].id]=++k;
        }
        memset(C,0,sizeof(C));
        for(int i=0;i<nn-1;i+=2){
            add(a[i],1);add(a[i+1]+1,-1);
        }
        printf("Case #%d:\n",++tt);
        for(int i=nn;i<mm;i++) printf("%d\n",getsum(a[i]));
    }
    return 0;
}
