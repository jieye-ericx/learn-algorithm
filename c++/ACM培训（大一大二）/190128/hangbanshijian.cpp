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
    int h,m,s,i,n,sa,db,da,sb,d;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d:%d:%d",&h,&m,&s);
        sa=h*3600+m*60+s;
        scanf("%d:%d:%d",&h,&m,&s);
        db=h*3600+m*60+s;
        ch=getchar();
        if(ch==' ') {
            scanf("(+%d)",&d);
            da+=d*24*3600;
        }
    }

    printf("%0d:%0d:%0d",h,m,s);
    system("pause");
	return 0;
}
