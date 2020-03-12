#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define N 500004
long long sum[N],ans,las;
int a[N];
int n,i,j,x,y;
struct node
{
    long long  l,r,w,f;
}tree[2000004];

void build(int k,int ll,int rr)//建树 
{
    tree[k].l=ll,tree[k].r=rr;
    if(tree[k].l==tree[k].r)
    {
        scanf("%d",&tree[k].w);
        a[++i]=tree[k].w;
        sum[i]=sum[i-1]+a[i];
        return;
    }
    int m=(ll+rr)/2;
    build(k*2,ll,m);
    build(k*2+1,m+1,rr);
    tree[k].w=min(tree[k*2].w,tree[k*2+1].w);
}
void ask_interval(int i,int j,int k)//区间查询 
{
    if(tree[k].l>=i&&tree[k].r<=j) 
    {
        ans=min(ans,tree[k].w);
        return;
    }
    int m=(tree[k].l+tree[k].r)/2;
    if(i<=m) ask_interval(i,j,k*2);
    if(j>m) ask_interval(i,j,k*2+1);
}
// int find(int i,int j){
//     int ae=100000000;
//     for(int x=i;x<=j;x++){
//         ae=min(a[x],ae);
//     }
//     return ae;
// }
void com(int i,int j){
    if(i==j) {
        las=max((long long)a[i]*a[i],las);
        return ;
    }
    ans=100000000;
    ask_interval(i,j,1);
    las=max((sum[j]-sum[i-1])*ans,las);
    com(i+1,j);
    com(i,j-1); 
}

int main()
{
    ios::sync_with_stdio(false);

    cin>>n;
    i=0;
    build(1,1,n);
    // for(j=0;j<=i;j++){
    //     cout<<a[j]<<" "<<sum[j]<<endl;
    // }
    // while(1){
    //     las=0;
    //     cin>>x>>y;
    //     ans=100000000;
    //     ask_interval(x,y,1);
    //     cout<<ans<<endl;
    // }
    
    // cin>>a[1];
    // sum[1]=a[1];
    // for(i=2;i<=n;i++){
    //     cin>>a[i];
    //     sum[i]=sum[i-1]+a[i];
    // }
    com(1,n);
    cout<<las<<"\n";
    // cin>>n;
    cin.get();
    cin.get();
    return 0;
}