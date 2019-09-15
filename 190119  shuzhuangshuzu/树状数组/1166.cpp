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
const int N = 5e4 + 10;
int t,n,tmp,i,j;
int c[N];
int lowbit(int i){
    return (i&-i);
}

void add(int i,int data){
    while(i<=n){
        c[i] += data;
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

int main(){
    scanf("%d",&t);
    for(int cnt=1;cnt<=t;cnt++){
        printf("Case %d:\n",cnt);
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&tmp);
            add(i,tmp);
        }

        char str[10];
        while(1){
            scanf(" %s",str);
            if(str[0] == 'E')break;

            scanf("%d %d",&i,&j);
            if(str[0] == 'A'){add(i,j);continue;}
            if(str[0] == 'S'){add(i,-j);continue;}
            if(str[0] == 'Q'){printf("%d\n",getSum(j) - getSum(i-1));continue;}
        }
        memset(c,0,sizeof(c));
    }
    return 0;
}
