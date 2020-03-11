#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100005
int c[N];
int n,x,y,i,sum,cnt;

struct node
{
    int i,k;
    bool operator < (const node &a) const{
        if(k != a.k) return k < a.k;
        return i < a.i;
    }
}p[N];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y){
    while(x<=8) {
        c[x]+=y;
        x+=lowbit(x);
    }
}
int getSum(int x){
    int ans = 0;
    while(x>0) {
		ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    for(i=1;i<=8;i++){
        add(i,1);
    }
    for(i=1;i<=8;i++){
        cout<<c[i]<<" ";
    }cout<<endl;
    for(i=1;i<=8;i++){
        cout<<getSum(i)<<" ";
    }
    system("pause");
	return 0;
}
