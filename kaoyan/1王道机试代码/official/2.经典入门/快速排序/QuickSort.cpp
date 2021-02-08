#include<stdio.h>
#include<algorithm>
using namespace std;
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
		sort(buf,buf+n);
		for(int m=0;m<n;m++)
		{
			printf("%d ",buf[m]);
		}
		printf("\n");
	}
}