#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)//×Ô¶¨ÒåÅÅÐò
{
	return x>y;
}
void main()
{
	int buf[100];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&buf[i]);
		}
		sort(buf,buf+n,cmp);
		for(int m=0;m<n;m++)
		{
			printf("%d ",buf[m]);
		}
		printf("\n");
	}
}