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
#define N 200003
int tree[N<<2],a[N];
int n,i,xi[N],m,maxY[N],k;
set<int> yi[N];

struct node
{
    int x,y;
    int type;
}order[N];

void push_up(int rt){
    maxY[rt]=max(maxY[rt<<1],maxY[rt<<1|1]);
}

//left:当前线段的左端点right:右端点rt:表示区间编号
void build(int left,int right,int rt){
    if(left==right){
        tree[left]=a[left];
        return;
    }
    int mid=(left+right)>>1;
    build(left,mid,rt<<1);
    build(mid+1,right,rt<<1|1);
    push_up(rt);
}

//将第k个值+v
void update_add(int left,int right,int rt,int k,int v){
    if(left==right){
        maxY[left]=v;
        yi[left].insert(v);
        return;
    }
    int mid=(left+right)>>1;
    if(k<=mid)
        update_add(left,mid,rt<<1,k,v);
    else
        update_add(mid+1,right,rt<<1|1,k,v);
    push_up(rt);
}

void update_remove(int left,int right,int rt,int k,int v){
    if(left==right){
        yi[left].erase(v);
        if(yi[left].empty()) 
            maxY[left]=0;
        else
            maxY[left]=*(yi[left].end()-1);
        return;
    }
    int mid=(left+right)>>1;
    if(k<=mid)
        update_remove(left,mid,rt<<1,k,v);
    else
        update_remove(mid+1,right,rt<<1|1,k,v);
    push_up(rt);
}

int query(int left,int right,int rt,int k,int v){
    if(maxY[rt]<=v) return -1;
    if(left==right){
        return left;
    }
    int mid=(left+right)>>1;
    if(mid<k){
        query(mid+1,right,rt<<1,k,v);
    }else{
        int t=query(left,mid,rt<<1,k,v);

    }
}                                                               

int main(){
    string ord;
    
    while(cin>>n){
        for(i=0;i<n;i++){
                cin>>ord;
            if(ord=="add") order[i].type=0;
            else if(ord=="remove") order[i].type=1;
            else order[i].type=2;
            cin>>order[i].x>>order[i].y;
            xi[i]=order[i].x;
        }
        sort(xi,xi+n);
        m=unique(xi,xi+m)-xi;
        for(i=0;i<n;i++){
            if(order[i].type==0){
                k=lower_bound(xi,xi+m,order[i].x)-xi;
                update_add(0,m-1,1,k,order[i].y);
            }else if(order[i].type==1){
                update_remove(0,m-1,1,k,order[i].y);
            }else{
                k=query(0,m-1,1,k+1,order[i].y);
                cout<<xi[k]<<' '<<*(yi[k].upper_bound(order[i].y))<<endl;
            }
        }
    }
    
    system("pause");
    return 0;
}