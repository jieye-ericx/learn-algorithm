/*hdu 1166 �б�����
    ��һ��һ������T����ʾ��T�����ݡ�
    ÿ�����ݵ�һ��һ��������N��N<=50000��,��ʾ������N������Ӫ�أ���������N��������,
	��i��������ai�����i������Ӫ���￪ʼʱ��ai���ˣ�1<=ai<=50����
    ������ÿ����һ�����������4����ʽ��
    (1) Add i j,i��jΪ������,��ʾ��i��Ӫ������j���ˣ�j������30��
    (2)Sub i j ,i��jΪ������,��ʾ��i��Ӫ�ؼ���j���ˣ�j������30��;
    (3)Query i j ,i��jΪ������,i<=j����ʾѯ�ʵ�i����j��Ӫ�ص�������;
    (4)End ��ʾ����������������ÿ������������;
    ÿ�����������40000������
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
