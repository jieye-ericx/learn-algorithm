/*ţ��С������5 interval
Apojacsleamϲ�����顣

    ��������һ��n��Ԫ�ص�����a������Ҫ��a[L]-a[R]����M�β�����
        ����һ����a[L]-a[R]�ڵ�Ԫ�ض�����P
        ����������a[L]-a[R]�ڵ�Ԫ�ض���ȥP
    ���ѯ��a[l]-a[r]�ڵ�Ԫ��֮�ͣ�

    ���빲M+3�У�
    ��һ����������n��M�������硰��Ŀ������
    �ڶ���n�������������顣
    ��3-M+2�У���M�У�ÿ���ĸ�����q��L��R��P����qΪ1���ʾִ�в���2������Ϊִ�в���1
    ��4�У�����������l��r
    1<=n,M<=1e6,�����������ݶ���int��Χ��.
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
