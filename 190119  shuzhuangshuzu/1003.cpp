/*hdu 1166 敌兵布阵
    第一行一个整数T，表示有T组数据。
    每组数据第一行一个正整数N（N<=50000）,表示敌人有N个工兵营地，接下来有N个正整数,
	第i个正整数ai代表第i个工兵营地里开始时有ai个人（1<=ai<=50）。
    接下来每行有一条命令，命令有4种形式：
    (1) Add i j,i和j为正整数,表示第i个营地增加j个人（j不超过30）
    (2)Sub i j ,i和j为正整数,表示第i个营地减少j个人（j不超过30）;
    (3)Query i j ,i和j为正整数,i<=j，表示询问第i到第j个营地的总人数;
    (4)End 表示结束，这条命令在每组数据最后出现;
    每组数据最多有40000条命令
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int a,b,i,j,m,l,d,r,k,h,x,cnt,n;
int c[N],c1[N];
int lowbit(int i){
    return (i&-i);
}

void add(int i,int data){
    while(i<=n){
        c[i] += data;
        i += lowbit(i);
    }
}
void add1(int i,int data){
    while(i<=n){
        c1[i] += data;
        i += lowbit(i);
    }
}

int getSum(int i){
    int sum = 0;
    while(i>0){
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int getSum1(int i){
    int sum = 0;
    while(i>0){
        sum += c1[i];
        i -= lowbit(i);
    }
    return sum;
}

int main(){
    while(scanf("%d",&n)&&n!=0){
        memset(c,0,sizeof(c));
        memset(c1,0,sizeof(c1));
        cnt=0;
        //
        cin>>m;
        for(i=0;i<m;i++){
            cin>>l>>r>>d;
            add(l,d);
            add(r+1,-d);
        }
        for(i=1;i<=n;i++){
            add1(i,getSum(i));
        }
        // for(i=1;i<=n;i++){
        //     cout<<getSum(i)<<" ";
        // }
        // cout<<endl;
        // for(i=1;i<=n;i++){
        //     cout<<getSum1(i)<<" ";
        // }
        long long HI=getSum1(n);
        cin>>k;
        for(i=0;i<k;i++){
            cin>>h>>x;
            if(h>HI-getSum(x-1)) cnt++;
        }
        cout<<cnt<<endl;
        
    }
    
    system("pause");
    return 0;
}