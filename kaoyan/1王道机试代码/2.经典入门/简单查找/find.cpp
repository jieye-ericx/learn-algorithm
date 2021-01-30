#include<stdio.h>
void main()
{
	int n,buf[1000],x;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&buf[i]);
		}
		scanf("%d",&x);
		int ans=-1;
		for(i=0;i<n;i++)
		{
			if(buf[i]==x)
			{
				ans=i;
				break;
			}
		}
		if(ans==-1)printf("not find");
		else printf("%d",ans);
	}
}