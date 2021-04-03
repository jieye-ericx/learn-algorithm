#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int Tree[101];
int findRoot(int x)
{
	if(Tree[x]==-1)return x;
	else return findRoot(Tree[x]);
}
struct Edge
{
	int a,b;
	double cost;
	bool operator <(const Edge &A)const
	{
		return cost<A.cost;
	}
}edge[6000];
struct Point
{
	double x,y;
	double getDistance(Point A)
	{
		double tmp=(x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);
		return sqrt(tmp);
	}
}point[101];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for(int i=1;i<=n;i++)Tree[i]=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}
		int num=0;
		for(i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)//双层循环注意i，j不要写错了
			{
				edge[num].a=i;
				edge[num].b=j;
				edge[num].cost=point[i].getDistance(point[j]);
				num++;
			}
		}
		sort(edge,edge+num);
		double ans=0;
		for(i=0;i<num;i++)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if(a!=b)
			{
				Tree[a]=b;
				ans+=edge[i].cost;
			}
		}
		printf("%.2lf",ans);
	}
	return 0;
}