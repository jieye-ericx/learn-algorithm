#include<stdio.h>
void main()
{
	int h;
	while(scanf("%d",&h)!=EOF)
	{
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<h-i-1;j++)printf(" ");
			for(j=h-i-1;j<2*h-1;j++)printf("*");
			printf("\n");

		}
	}
}
