#include<stdio.h>
int n,m,t;
char maze[50][50];
bool success;
int go[4][2]=
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
void DFS(int x,int y,int time)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<0||nx>=n||ny<0||ny>=m)continue;
		if(maze[nx][ny]=='X')continue;
		if(maze[nx][ny]=='D')
		{
			if(time+1==t)
			{
				success=true;
				return;
			}
		}
		maze[nx][ny]='X';
		DFS(nx,ny,time+1);
		maze[nx][ny]='.';
		if(success==true)return;
	}
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		if(n==0&&m==0&&t==0)break;
		success=false;
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
		}
		int x,y;
		for(i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='S')
				{
					x=i;
					y=j;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='D'&&(i+j)%2==((x+y)%2+t%2)%2)
				{
					maze[x][y]='X';
					DFS(x,y,0);
				}
			}
		}
		if(success==true)printf("YES");
		else printf("NO");
	}
	return 0;
}
