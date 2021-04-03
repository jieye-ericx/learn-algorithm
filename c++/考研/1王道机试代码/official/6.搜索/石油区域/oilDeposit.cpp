#include<stdio.h>
char maze[50][50];
bool mark[50][50];
int n,m;
int go[8][2]=
{
	1,0,
	-1,0,
	0,1,
	0,-1,
	1,1,
	1,-1,
	-1,1,
	-1,-1
};
void DFS(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<0||nx>=n||ny<0||ny>=m)continue;
		if(mark[nx][ny]==true)continue;
		if(maze[nx][ny]=='*')continue;
		mark[nx][ny]=true;
		DFS(nx,ny);
	}
	return;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);//注意书上给的是maze[i]+1,那是因为其他的存储位置都是从1开始的，这里也从1开始
		}
		for(i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				mark[i][j]=false;
			}
		}
		int ans=0;
		for(i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mark[i][j]==true)continue;
				if(maze[i][j]=='*')continue;
				mark[i][j]=true;
				DFS(i,j);
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}