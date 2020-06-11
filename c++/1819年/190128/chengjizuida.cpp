#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
using namespace std;
#define N 100003
int n,k,i,t,j;

struct node{
    int i,j;
} p[N];
bool tmp(node n1,node n2){
    if(n1.j!=n2.j)
    return n1.j>n2.j;
    else return n1.i>n2.i;
}
int main(){
    ios::sync_with_stdio(false);
    while(scanf("%d%d",&n,&t)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&k);
            if(k>=0) {p[i].i=1;p[i].j=k;}
            else {p[i].i=-1,p[i].j=-k;}
        }
        sort(p,p+n,tmp);
        for(i=0;i<n;i++){
            cout<<p[i].i<<" "<<p[i].j<<endl;
        }

        
    }
    system("pause");
	return 0;
}
