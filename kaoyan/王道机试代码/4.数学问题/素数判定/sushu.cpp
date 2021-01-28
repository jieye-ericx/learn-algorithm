#include<stdio.h>
#include<math.h>
bool judge(int x)
{
	if(x<=1)return false;
	int bound=(int)sqrt(x)+1;
	for(int i=2;i<bound;i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
void main()
{
	/*int a;
	while(scanf("%d",&a)!=EOF)
	{
		puts(judge(a)?"yes":"no");
		printf("\n");
	}*/
	for(int i=100000;i>0;i--)
	{
		if(judge(i)==true)
		{
			printf("%d",i);
			break;
		}
	}
}