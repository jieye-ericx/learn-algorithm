/*hdu 1556
    N�������ų�һ�ţ����������α��Ϊ1,2,3....N.ÿ�θ���2������a b(a <= b)
    ,lele��Ϊ�������ġ�С�ɸ�"�Ƶ綯��������a��ʼ������b���θ�ÿ������Ϳһ����ɫ��
    ����N���Ժ�lele�Ѿ������˵�I�������Ѿ�Ϳ��������ɫ�ˣ����ܰ������ÿ������Ϳ��������ɫ��

    ÿ������ʵ����һ��Ϊһ������N,(N <= 100000).��������N�У�ÿ�а���2������a b(1 <= a <= b <= N)��
    ��N = 0�����������

    ÿ������ʵ�����һ�У�����N����������I���������I�������ܹ���Ϳɫ�Ĵ�����
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
