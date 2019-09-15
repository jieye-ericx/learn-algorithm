#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
using namespace std;
#define N 50000
int tree[N<<2],a[N];

void push_up(int rt){
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}

//left:当前线段的左端点right:右端点rt:表示区间编号
void build(int left,int right,int rt){
    if(left==right){
        tree[left]=a[left];
    }
    int mid=(left+right)>>1;
    build(left,mid,rt<<1);
    build(mid+1,right,rt<<1|1);
    push_up(rt);
}

//将第k个值+v
int update(int left,int right,int rt,int k,int v){
    if(left==right){
        tree[rt]+=v;
    }
    int mid=(left+right)>>1;
    update(left,mid,rt<<1,k,v);
    update(mid+1,right,rt<<1|1,k,v);
    push_up(rt);
}

int query(int left,int right,int rt,int L,int R){
    if(L==left &&right==R){
        return tree[rt];
    }
    int mid=(right+left)>>1;
    int ret=0;
    if(R<=mid){
        ret+=query(left,mid,rt<<1|1,L,R);
    }else if(L>mid){
        ret+=query(mid+1,right,rt<<1|1,L,R);
    }else{
        ret+=query(left,mid,rt<<1,L,mid);
        ret+=query(mid+1,right,rt<<1|1,mid+1,R);
    }
    return ret;
}

int main(){
    int n,i,i1,j1;
    string order;
    while(cin>>n){
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        build(0,n-1,1);
        
        while(cin>>order,order!="End"){
            cin>>j1>>i1;
            if(order=="Add"){
                update(0,n-1,1,i1,j1);
            }else if(order=="Sub"){
                update(0,n-1,1,i1,-j1);
            }else if(order=="Query"){
                //query(0,n-1,1,1);
            }
        }
        
    }
    
    system("pause");
    return 0;
}