#include<stdio.h>
void main()
{
	char a[10],b[10];
	while(scanf("%s%s",&a,&b)!=EOF)
	{
		int sum=0;
		for(int i=0;a[i]!=0;i++)
		{
			for(int j=0;b[j]!=0;j++)
			{
				sum+=(a[i]-'0')*(b[j]-'0');
			}
		}
		printf("%d\n",sum);
	}
}