#include<stdio.h>
#include<vector>
using namespace std;
struct E
{
	int next;
	int c;
};
vector<E> edge[101];
bool mark[101];
int dis[101];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)break;
		for(int i=1;i<=n;i++)edge[i].clear();
		int a,b,c;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c=c;
			tmp.next=b;
			edge[a].push_back(tmp);
			tmp.next=a;
			edge[b].push_back(tmp);
		}
		for(i=1;i<=n;i++)
		{
			dis[i]=-1;
			mark[i]=false;
		}
		dis[1]=0;
		mark[1]=true;
		int newP=1;
		for(i=1;i<n;i++)
		{
			for(int j=0;j<edge[newP].size();j++)
			{
				int t=edge[newP][j].next;
				int c=edge[newP][j].c;
				if(mark[t]==true)continue;
				if(dis[t]==-1||dis[t]>dis[newP]+c)dis[t]=dis[newP]+c;
			}
			int min=123123;
			for(int k=1;k<=n;k++)//注意这里不是edge[newp].size()
			{
				if(mark[k]==true)continue;
				if(dis[k]==-1)continue;
				if(dis[k]<min)
				{
					min=dis[k];
					newP=k;
				}
			}
			mark[newP]=true;
		}
		printf("%d",dis[n]);
	}
	return 0;
}