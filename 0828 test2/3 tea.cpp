#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
using namespace std;
int t,n,i,e,ty,k,x,num;
int a[100004],b[100004],ret[100004],vis[100004];

struct node
{
    int parent;
    int sum;
    node():sum(0){

    }

}da[100004];

int find(int x){
    if(x=da[x].parent){
        return x;
    }
    da[x].parent=find(da[x].parent);
    return da[x].parent;
}

void Union(int x,int y){
    x=find(x),y=find(y);
    if(x!=y){
        da[x].parent=y;
        da[y].sum+=da[x].sum;
    }
}

void ini(){
    int i;
    for(i=1;i<=n;i++){
        da[i].parent=i;
        da[i].sum=a[i];
    }
}

int main(){
    int i;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    ini();
    ret[0]=0;
    priority_queue<int>pq;
    for(i=n-1;i>=0;i--){
        if(b[i]>1 && vis[b[i]-1]){
            Union(b[i],b[i]-1);
            x=find(b[i]);
            pq.push(da[x].sum);
        }
        if(b[i]<n && vis[b[i]+1]){
            Union(b[i],b[i]+1);
            x=find(b[i]);
            pq.push(da[x].sum);
        }
        ret[i-1]=pq.top();
    }
    for(i=0;i<n;i++)cout<<ret[i]<<endl;
    system("pause");
    return 0;
}