#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int n,p,m,x,y,ans;
int a
struct node
{
    int l,r,w,f;
}tree[400001];
inline void build(int k,int ll,int rr)//建树 
{
    tree[k].l=ll,tree[k].r=rr;
    if(tree[k].l==tree[k].r)
    {
        scanf("%d",&tree[k].w);
        return;
    }
    int m=(ll+rr)/2;
    build(k*2,ll,m);
    build(k*2+1,m+1,rr);
    tree[k].w=tree[k*2].w^tree[k*2+1].w;
}
// inline void down(int k)//标记下传 
// {
//     tree[k*2].f+=tree[k].f;
//     tree[k*2+1].f+=tree[k].f;
//     tree[k*2].w^=tree[k].f*(tree[k*2].r-tree[k*2].l+1);
//     tree[k*2+1].w+=tree[k].f*(tree[k*2+1].r-tree[k*2+1].l+1);
//     tree[k].f=0;
// }
inline void ask_point(int k)//单点查询
{
    if(tree[k].l==tree[k].r)
    {
        ans=tree[k].w;
        return ;
    }
    int m=(tree[k].l+tree[k].r)/2;
    if(x<=m) ask_point(k*2);
    else ask_point(k*2+1);
}

inline void ask_interval(int a,int b,int k)//区间查询 
{
    if(tree[k].l>=a&&tree[k].r<=b) 
    {
        ans^=tree[k].w;
        return;
    }
    int m=(tree[k].l+tree[k].r)/2;
    if(a<=m) ask_interval(k*2);
    if(b>m) ask_interval(k*2+1);
}
int main()
{
    ios::sync_with_stdio(false);

    cin>>t;
    while(t--){
        build(1,1,n);
        cin>>q;
        for(int y=0;y<q;y++){
            cin>>i>>j;
        }
    }
    
    for(int i=0;i<10;i++){
        cin>>a>>b;
        cout<<(a^b)<<endl;
    }
    
    return 0;
}