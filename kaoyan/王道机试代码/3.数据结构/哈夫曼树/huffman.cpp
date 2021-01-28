#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int, vector<int>,greater<int> >Q;
void main()
{
	int n,x;
	while(scanf("%d",&n)!=EOF)
	{
		while(Q.empty()==false)Q.pop();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			Q.push(x);
		}
		int ans=0;
		while(Q.size()>1)
		{
			int a=Q.top();
			Q.pop();
			int b=Q.top();
			Q.pop();
			ans+=a+b;
			Q.push(a+b);
		}
		printf("%d",ans);
	}
}
