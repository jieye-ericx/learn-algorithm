#include<stdio.h>
void main()
{
	int OutPut[80][80];
	int n;
	char a,b;
	while(scanf("%d %c %c",&n,&a,&b)==3)
	{
		for(int i=1,j=1;i<=n;i+=2,j++)
		{
			int x=n/2+1;
			x-=j-1;
			int y=x;
			char c=(j%2==0?b:a);
			for(int k=1;k<=i;k++)
			{
				OutPut[x+k-1][y]=c;
				OutPut[x][y+k-1]=c;
				OutPut[x+i-1][y+k-1]=c;
				OutPut[x+k-1][y+i-1]=c;
			}

		}
		if(n!=1)
		{
			OutPut[1][1]=' ';
			OutPut[1][n]=' ';
			OutPut[n][1]=' ';
			OutPut[n][n]=' ';
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%c",OutPut[i][j]);
			}
			printf("\n");
		}
	}
}