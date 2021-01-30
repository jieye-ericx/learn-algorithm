#include<stdio.h>
#include<string.h>
void main()
{
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,&b)!=EOF)
	{
		int length=strlen(str);
		int tmp=0;
		int c=1;
		int x;
		for(int i=length-1;i>=0;i--)
		{
			if(str[i]>='0'&&str[i]<='9')
			{
				x=str[i]-'0';
			}
			else if(str[i]>='a'&&str[i]<='z')
			{
				x=str[i]-'a'+10;
			}
			else if(str[i]>='A'&&str[i]<='Z')
			{
				x=str[i]-'A'+10;
			}
			tmp+=x*c;
			c*=a;
		}
		char ans[40];
		int size=0;
		int y;
		do
		{
			y=tmp%b;
			ans[size++]=(y>10)?(y-10+'a'):(y+'0');
			tmp/=b;
		}while(tmp!=0);
		for(i=size-1;i>=0;i--)
		{
			printf("%c",ans[i]);
		}
		printf("\n");
	}
}