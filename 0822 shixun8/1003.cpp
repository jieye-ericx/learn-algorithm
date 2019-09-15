#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 40000;
int p[maxn];

void table_p()//生成素数表
{
    memset(p,0,sizeof(p));
    for(int i=2;i<=maxn;i++)
    {
        if(!p[i])
        {
            for(int j=i*i;i<=maxn;j+=i)//后面的i的倍数一定不是素数
                p[j]=1;
        }
    }
}
int main()
{
    int t,e=1,n;
    scanf("%d",&t);
    while(t--)
    {
        printf("Scenario #%d:\n",e);
        scanf("%d",&n);
        int sum=1,k;
        int i;
        for(i=2;i<=maxn;i++)
        {
            if(n==1)
                break;
            if(!p[i])
            {
                k=0;
                while(n%i==0)
                {
                    k++;
                    n/=i;
                }
                sum*=2*k+1;//根据假设n=a^x*b^y*c^z,所以n的因子的个数为(1+x)(1+y)(1+z),为什么呢？因为x可以取到0~x,(y和z同理)。又因为我们要求的是n*n的因子数，n*n=a^2x*b^2y*c^2z,所以n*n的因子数为(1+2x)(1+2y)(1+2z)
            }
        }
        if(n>1)
            sum*=3;
        printf("%d\n\n",(sum+1)/2);
        e++;

    }
    return 0;
}