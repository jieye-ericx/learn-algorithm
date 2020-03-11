/*hdu 1556
    N个气球排成一排，从左到右依次编号为1,2,3....N.每次给定2个整数a b(a <= b)
    ,lele便为骑上他的“小飞鸽"牌电动车从气球a开始到气球b依次给每个气球涂一次颜色。
    但是N次以后lele已经忘记了第I个气球已经涂过几次颜色了，你能帮他算出每个气球被涂过几次颜色吗？

    每个测试实例第一行为一个整数N,(N <= 100000).接下来的N行，每行包括2个整数a b(1 <= a <= b <= N)。
    当N = 0，输入结束。

    每个测试实例输出一行，包括N个整数，第I个数代表第I个气球总共被涂色的次数。
*/
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int a,b,n;
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
    while(scanf("%d",&n)!=0,n){
        memset(c,0,sizeof(c));

        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            add(a,1);
			add(b+1,-1);
        }
        for(int i=1;i<=n;i++)
            cout<<c[i]<<" ";
            cout<<endl;
		for(int i=1;i<=n;i++)
            cout<<getSum(i)<<" ";
//        for(int i=1;i<n;i++)
//			printf("%d ",getSum(i));
//        printf("%d\n",getSum(n));
    }
    return 0;
}
