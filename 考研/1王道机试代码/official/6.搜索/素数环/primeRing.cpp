#include<stdio.h>
int prime[12]={2,3,5,7,11,13,17,19,23,29,31,37};
bool mark[20];
int ans[20];
int n;
bool judge(int x)
{
	for(int i=0;i<12;i++)
	{
		if(prime[i]==x)return true;
	}
	return false;
}
void check()
{
	if(judge(ans[n]+ans[1])==false)return;
	for(int i=1;i<=n;i++)
	{
		if(i!=1)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}
void DFS(int num)
{
	if(num>1)
	{
		if(judge(ans[num]+ans[num-1])==false)return;
	}
	if(num==n)check();
	for(int i=2;i<=n;i++)
	{
		if(mark[i]==true)continue;
		mark[i]=true;
		ans[num+1]=i;
		DFS(num+1);
		mark[i]=false;
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)mark[i]=false;
		ans[1]=1;
		mark[1]=true;
		DFS(1);
	}
	return 0;
}