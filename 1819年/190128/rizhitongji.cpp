#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
#define N 100004
int n,d,k,i,j,a,b;
set<int> g[N],t;
struct node{
    int ts,id;
} p[N];

bool tmp(node p1,node p2){
    if(p1.id!=p2.id) return p1.id<p2.id;
    return p1.ts<p2.ts;
}

int main(){
    while(scanf("%d%d%d",&n,&d,&k)!=EOF){
        for(i=0;i<n;i++){
            //scanf("%d%d",&p[i].ts,&p[i].id);
            scanf("%d%d",&a,&b);
            g[b].insert(a);
            t.insert(b);
        }
        set<int>::iterator it;
        for(it=t.begin();it<t.end();it++){
            //sort(g[t[i]]);
            if(g[t[i]].size()<k) t.erase(t[i]);
        }
    
        // sort(p,p+n,tmp);
        // for(i=0;i<n;i++){
        //         printf("%d %d\n",p[i].ts,p[i].id);
        // }

    }
    system("pause");
	return 0;
}
