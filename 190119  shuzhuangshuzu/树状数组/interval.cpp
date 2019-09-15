/*牛客小白月赛5 interval
Apojacsleam喜欢数组。

    他现在有一个n个元素的数组a，而他要对a[L]-a[R]进行M次操作：
        操作一：将a[L]-a[R]内的元素都加上P
        操作二：将a[L]-a[R]内的元素都减去P
    最后询问a[l]-a[r]内的元素之和？

    输入共M+3行：
    第一行两个数，n，M，意义如“题目描述”
    第二行n个数，描述数组。
    第3-M+2行，共M行，每行四个数，q，L，R，P，若q为1则表示执行操作2，否则为执行操作1
    第4行，两个正整数l，r
    1<=n,M<=1e6,所有输入数据都在int范围内.
*/
#include<iostream>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
int n,m;
ll c[N];
int lowbit(int i){
    return (i&-i);
}
void add(int i,int data){
    while(i<=n){
        c[i] += data;
        i += lowbit(i);
    }
}

ll getSum(int i){
    ll sum = 0;
    while(i>0){
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main(){
    scanf("%d %d",&n,&m);
    int tmp,bef;
    bef = 0;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&tmp);
        add(i,tmp - bef);bef = tmp;
    }
    int o,l,r,data;
    while(m--){
        scanf("%d %d %d %d",&o,&l,&r,&data);
        if(o == 1){add(l,-data);add(r+1,data);continue;}
        add(l,data);add(r+1,-data);
    }
    scanf("%d %d",&l,&r);
    ll ans = 0;
    for(ll i=l;i<=r;i++)ans += getSum(i);
    printf("%lld\n",ans);
    return 0;
}

#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n,a[N],d[N],m;

int main(){
    scanf("%d %d",&n,&m);
    a[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[i] = a[i] - a[i-1];
    }
    int o,l,r,x;
    while(m--){
        scanf("%d %d %d %d",&o,&l,&r,&x);
        if(o==1){d[l]-=x;d[r+1]+=x;continue;}
        d[l]+=x; d[r+1]-=x;
    }

    scanf("%d %d",&l,&r);
    a[1]=d[1];
    for(int i=1;i<=r;i++)a[i]=d[i]+a[i-1];

    long long ans=0;
    for(int i=l;i<=r;i++)ans+=a[i];
    printf("%lld\n",ans);
    return 0;
}
