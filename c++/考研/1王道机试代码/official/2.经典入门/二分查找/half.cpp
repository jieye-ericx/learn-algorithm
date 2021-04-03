#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct student
{
	char sno[100];
	char name[100];
	char sex[10];
	int age;
	bool operator < (const student &b) const
	{
		return strcmp(sno,b.sno)<0;
	}
}buf[1000];
void main()
{
	int n,m;
	char x[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s %s %s %d",&buf[i].sno,&buf[i].name,&buf[i].sex,&buf[i].age);
		}
		sort(buf,buf+n);
		scanf("%d",&m);
		while(m--!=0)
		{
			int ans=-1;
			scanf("%s",&x);
			int top=n-1,base=0;
			int cnt=1;
			while(top>=base)
			{
				int mid=(top+base)/2;
				int tmp=strcmp(buf[mid].sno,x);
				if(tmp==0)
				{
					ans=mid;
					break;
				}
				else if(tmp<0)base=mid+1;
				else top=mid-1;
				printf("%d\t",mid);
				printf("%d\t",cnt++);
			}
			if(ans==-1)printf(" not find");
			else printf("%s %s %s %d\n",buf[ans].sno,buf[ans].name,buf[ans].sex,buf[ans].age);
		}
	}
}