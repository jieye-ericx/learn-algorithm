
#include <stdio.h>
#include <string.h>
int zy[1000];
int a[1000];
int k;
void zhi(int n) //存储n的质因数
{
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            zy[k++] = i;
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        zy[k++] = n;
}
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        memset(a, 0, sizeof(a));
        memset(zy, 0, sizeof(zy));
        k = 0;
        zhi(n);
        int i, j;
        int sum = 1;
        for (i = 0; i < k; i++)
        {
            int sun = 0; //记录每个质因数的个数
            while (n % zy[i] == 0)
            {
                sun++;
                n /= zy[i];
            }
            sum *= (sun + 1); //将他们相乘
        }
        printf("%d\n", sum);
    }
    return 0;
}
