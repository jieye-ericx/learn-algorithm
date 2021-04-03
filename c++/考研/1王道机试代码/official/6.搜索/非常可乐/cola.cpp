#include<stdio.h>
#include<queue>
using namespace std;
struct E
{
	int a,b,c;
	int t;
};//忘记加;会导致无法调用Q.empty()
queue<E> Q;
bool mark[50][50][50];
void A2B(int &a,int sa,int &b,int sb)
{
	if(a<=sb-b)
	{
		b+=a;
		a=0;
	}
	else 
	{
		a-=sb-b;
		b=sb;
	}
}
int BFS(int s,int n,int m)
{
	while(Q.empty()==false)
	{
		E now=Q.front();
		Q.pop();//记得写，否则无限循环
		int a,b,c;
		a=now.a;
		b=now.b;
		c=now.c;
		A2B(a,s,b,n);
		if(mark[a][b][c]==false)
		{
			mark[a][b][c]=true;
			E tmp;
			tmp.a=a;
			tmp.b=b;
			tmp.c=c;
			tmp.t=now.t+1;
			if(a==s/2&&b==s/2)return tmp.t;
			if(a==s/2&&c==s/2)return tmp.t;
			if(c==s/2&&b==s/2)return tmp.t;
			Q.push(tmp);
		}
		a=now.a;
		b=now.b;
		c=now.c;
		A2B(b,n,a,s);
		if(mark[a][b][c]==false)
		{
			mark[a][b][c]=true;
			E tmp;
			tmp.a=a;
			tmp.b=b;
			tmp.c=c;
			tmp.t=now.t+1;
			if(a==s/2&&b==s/2)return tmp.t;
			if(a==s/2&&c==s/2)return tmp.t;
			if(c==s/2&&b==s/2)return tmp.t;
			Q.push(tmp);
		}
		a=now.a;
		b=now.b;
		c=now.c;
		A2B(a,s,c,m);
		if(mark[a][b][c]==false)
		{
			mark[a][b][c]=true;
			E tmp;
			tmp.a=a;
			tmp.b=b;
			tmp.c=c;
			tmp.t=now.t+1;
			if(a==s/2&&b==s/2)return tmp.t;
			if(a==s/2&&c==s/2)return tmp.t;
			if(c==s/2&&b==s/2)return tmp.t;
			Q.push(tmp);
		}
		a=now.a;
		b=now.b;
		c=now.c;
		A2B(c,m,a,s);
		if(mark[a][b][c]==false)
		{
			mark[a][b][c]=true;
			E tmp;
			tmp.a=a;
			tmp.b=b;
			tmp.c=c;
			tmp.t=now.t+1;
			if(a==s/2&&b==s/2)return tmp.t;
			if(a==s/2&&c==s/2)return tmp.t;
			if(c==s/2&&b==s/2)return tmp.t;
			Q.push(tmp);
		}
		a=now.a;
		b=now.b;
		c=now.c;
		A2B(c,m,b,n);
		if(mark[a][b][c]==false)
		{
			mark[a][b][c]=true;
			E tmp;
			tmp.a=a;
			tmp.b=b;
			tmp.c=c;
			tmp.t=now.t+1;
			if(a==s/2&&b==s/2)return tmp.t;
			if(a==s/2&&c==s/2)return tmp.t;
			if(c==s/2&&b==s/2)return tmp.t;
			Q.push(tmp);
		}
		a=now.a;
		b=now.b;
		c=now.c;
		A2B(b,n,c,m);
		if(mark[a][b][c]==false)
		{
			mark[a][b][c]=true;
			E tmp;
			tmp.a=a;
			tmp.b=b;
			tmp.c=c;
			tmp.t=now.t+1;
			if(a==s/2&&b==s/2)return tmp.t;
			if(a==s/2&&c==s/2)return tmp.t;
			if(c==s/2&&b==s/2)return tmp.t;
			Q.push(tmp);
		}
	}
	return -1;
}
int main()
{
	int s,n,m;
	while(scanf("%d%d%d",&s,&n,&m)!=EOF)
	{
		if(s==0)break;
		if(s%2==1)
		{
			printf("NO\n");
			continue;
		}
		for(int i=0;i<=s;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=m;k++)
				{
					mark[i][j][k]=false;
				}
			}
		}
		E tmp;
		tmp.a=s;
		tmp.b=tmp.c=tmp.t=0;
		while(Q.empty()==false)Q.pop();
		Q.push(tmp);
		int rec=BFS(s,n,m);
		if(rec==-1)printf("NO\n");
		else printf("%d\n",rec);
	}
	return 0;
}