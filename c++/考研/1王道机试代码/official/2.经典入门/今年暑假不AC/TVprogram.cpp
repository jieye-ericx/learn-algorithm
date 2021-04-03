#include<stdio.h>
#include<algorithm>
using namespace std;
struct TV
{
	int starttime;
	int endtime;
	bool operator<(const TV &b)const
	{
		return endtime<b.endtime;
	}
}buf[100];
void main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&buf[i].starttime,&buf[i].endtime);
		}
		sort(buf,buf+n);
		int ans=0;
		int etime=0;
		for(i=0;i<n;i++)
		{
			if(buf[i].starttime>=etime)
			{
				ans++;
				etime=buf[i].endtime;
				printf("%d\n",etime);
			}
		}
		printf("%d\n",ans);
	}
}