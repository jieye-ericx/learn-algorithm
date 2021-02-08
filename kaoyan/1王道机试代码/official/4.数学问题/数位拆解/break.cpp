#include<stdio.h>
void main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int buf1[20],buf2[20];
		int i=0;
		while(a)
		{
			buf1[i++]=a%10;
			a/=10;
		}
		int j=0;
		while(b)
		{
			buf2[j++]=b%10;
			b/=10;
		}
		int sum=0;
		for(int k=0;k<i;k++)
		{
			for(int m=0;m<j;m++)
			{
				sum+=buf1[k]*buf2[m];
			}
		}
		printf("%d",sum);
	}
}