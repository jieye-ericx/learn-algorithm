#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[101];
queue<int> Q;
int indegree[101];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)break;
		for(int i=0;i<n;i++)
		{
			indegree[i]=0;
			edge[i].clear();
		}
		int a,b;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			indegree[b]++;
			edge[a].push_back(b);
		}
		while(Q.empty()==false)Q.pop();
		for(i=0;i<n;i++)
		{
			if(indegree[i]==0)Q.push(i);
		}
		int cnt=0;
		while(Q.empty()==false)
		{
			int t=Q.front();
			Q.pop();
			cnt++;
			for(i=0;i<edge[t].size();i++)
			{
				indegree[edge[t][i]]--;
				if(indegree[edge[t][i]]==0)Q.push(edge[t][i]);
			}
		}
		if(cnt==n)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}