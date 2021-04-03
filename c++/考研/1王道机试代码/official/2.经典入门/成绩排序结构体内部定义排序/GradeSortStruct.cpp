#include<stdio.h>
#include<algorithm>
using namespace std;
struct E
{
	char name[100];
	int age;
	int grade;
	bool operator<(E &b)const
	{
		if(grade!=b.grade)return grade<b.grade;
		int tmp=strcmp(name,b.name);
		if(tmp!=0)return tmp<0;
		else return age<b.age;
	}
}buf[100];
void main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s%d%d",&buf[i].name,&buf[i].age,&buf[i].grade);
		}
		sort(buf,buf+n);
		for(i=0;i<n;i++)
		{
			printf("%s\t%d\t%d\n",buf[i].name,buf[i].age,buf[i].grade);
		}
	}
}