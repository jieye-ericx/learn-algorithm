#include<stdio.h>
void main()
{
	int Hash[101];
	int n,score,x;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<101;i++)Hash[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&score);
			Hash[score]++;
		}
		scanf("%d",&x);
		printf("%d",Hash[x]);
	}
}