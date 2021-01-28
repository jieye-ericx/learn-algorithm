#include<stdio.h>
#include<vector>
using namespace std;
struct E
{
	int next,distance,cost;
};
vector<E> edge[101];
int dis[101],cost[101];
bool mark[101];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)break;
		for(int i=1;i<=n;i++)edge[i].clear();
		int a,b,c,d;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			E tmp;
			tmp.distance=c;
			tmp.cost=d;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		for(i=1;i<=n;i++)
		{
			dis[i]=-1;
			mark[i]=false;
			cost[i]=0;
		}
		dis[s]=0;
		mark[s]=true;
		int newP=s;
		for(i=1;i<n;i++)
		{
			for(int j=0;j<edge[newP].size();j++)
			{
				int to=edge[newP][j].next;
				int jl=edge[newP][j].distance;
				int hf=edge[newP][j].cost;
				if(mark[to]==true)continue;
				if(dis[to]==-1||dis[to]>dis[newP]+jl||dis[t]==dis[newP]+jl&&cost[to]>cost[newP]+hf)
				{
					dis[to]=dis[newP]+jl;
					cost[to]=cost[newP]+hf;
				}
			}
			int min=123123;
			for(int k=1;k<=n;k++)
			{
				if(dis[k]==-1)continue;
				if(mark[k]==true)continue;
				if(dis[k]<min)
				{
					min=dis[k];
					newP=k;
				}
			}
			mark[newP]=true;
		}
		printf("%d %d\n",dis[t],cost[t]);
	}
	return 0;
}

