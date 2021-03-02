#include<stdio.h>
int Tree[100];
int findRoot(int x)
{
	if(Tree[x]==-1)return x;
	else return findRoot(Tree[x]);
}
int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++)Tree[i]=-1;
		int a,b;
		while(m--!=0)
		{
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)Tree[a]=b;
		}
		int ans=0;
		for(i=1;i<=n;i++)
		{
			if(Tree[i]==-1)ans++;
		}
		printf("%d\n",ans-1);
	}
	return 0;
}