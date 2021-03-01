#include<stdio.h>
#define OFFSET 50000
void main()
{
	int hash[100001];
	int n,x,m;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		for(int i=-50000;i<=50000;i++)hash[i+OFFSET]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			hash[x+OFFSET]=1;
		}
		for(i=50000;i>-50000;i--)
		{
			if(hash[i+OFFSET]==1)
			{
				printf("%d",i);
				m--;
				if(m!=0)printf("\t");
				else 
				{
					printf("\n");
					break;
				}
			}
		}
	}
}
