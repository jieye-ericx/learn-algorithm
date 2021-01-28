#include<stdio.h>
#include<queue>
using namespace std;
struct E
{
	int x,y,z;
	int t;
};
queue<E> Q;
int maze[50][50][50];
int go[6][3]=
{
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
int BFS(int a,int b,int c)
{
	while(Q.empty()==false)
	{
		E now=Q.front();
		Q.pop();
		for(int i=0;i<6;i++)
		{
			int nx=now.x+go[i][0];
			int ny=now.y+go[i][1];
			int nz=now.z+go[i][2];
			if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)continue;
			if(maze[nx][ny][nz]==1)continue;
			maze[nx][ny][nz]=1;
			E tmp;
			tmp.x=nx;
			tmp.y=ny;
			tmp.z=nz;
			tmp.t=now.t+1;
			Q.push(tmp);
			if(nx==a-1&&ny==b-1&&nz==c-1)return tmp.t;
		}
	}
	return -1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,t;
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				for(int k=0;k<c;k++)
				{
					scanf("%d",&maze[i][j][k]);//缺少&,导致只输入一行就结束
				}
			}
		}
		while(Q.empty()==false)Q.pop();
		E tmp;
		tmp.x=tmp.y=tmp.z=tmp.t=0;
		Q.push(tmp);
		int rec=BFS(a,b,c);
		if(rec<=t)printf("%d\n",rec);
		else printf("-1\n");
	}
	return 0;
}