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
using namespace std;

int m,n,k,a,b,i,j,num;
int gar[1001][1001];
int parent[1000002];
int find(int x){
    if(x==parent[x]) return x;
    int t,y,p=parent[x];
    while(p!=parent[p]){
        p=parent[p];
    }
    t=p;
    p=x;
    while(p!=parent[p]){
        y=p;
        p=parent[p];
        parent[y]=t;
    }

    return p;
}

void uni(int a,int b){
    if(find(a)<find(b))
        parent[find(b)]=find(a);
    else
        parent[find(a)]=find(b);
}
int main(){
    while(cin>>m>>n){
        memset(gar,0,sizeof(gar));
        for(i=1;i<=m*n;i++){
            parent[i]=i;
        }
        num=0;
        //

        cin>>k;
        for(i=0;i<k;i++){
            cin>>a>>b;
            uni(a,b);
        }
        for(i=1;i<=m*n;i++){
            if(i==parent[i]) num++;
        }
        cout<<num<<endl;
        // for(i=1;i<=m*n;i++){
        //     cout<<"i="<<i<<" "<<"parent[i]="<<parent[i]<<endl;
        // }
    }
    system("pause");
    return 0;
}