#include<stdio.h>
#define N  1001
int Tree[N];
int sum[N];
int findRoot(int x)
{
	if(Tree[x]==-1)return x;
	else return findRoot(Tree[x]);
}
int main()
{
	int hello;
	while(scanf("%d",&hello)!=EOF)
	{
		for(int i=1;i<=N;i++)
		{
			Tree[i]=-1;
			sum[i]=1;
		}
		int a,b;
		while(hello--!=0)
		{
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
			{
				Tree[a]=b;
				sum[b]+=sum[a];
			}
		}
		int max=0;
		for(i=1;i<=N;i++)
		{
			if(Tree[i]==-1&&sum[i]>max)max=sum[i];
		}
		printf("%d\n",max);
	}
	return 0;
}