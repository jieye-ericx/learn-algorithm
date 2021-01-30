#include<stdio.h>
#include<string.h>
#define IsYeap(x) x%100!=0&&x%4==0 ||x%400==0?1:0
int DayOfMonth[13][2]=
{
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
char MonthName[13][20]=
{
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
char WeekName[7][20]=
{
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};
int buf[3001][13][32];
struct Date
{
	int Day;
	int Month;
	int Year;
	void nextDay()
	{
		Day++;
		if(Day>DayOfMonth[Month][IsYeap(Year)])
		{
			Day=1;
			Month++;
			if(Month>12)
			{
				Month=1;
				Year++;
			}
		}
	}
};
void main()
{
	Date tmp;
	tmp.Day=1;
	tmp.Month=1;
	tmp.Year=0;
	int cnt=0;
	while(tmp.Year<3001)
	{
		buf[tmp.Year][tmp.Month][tmp.Day]=cnt;
		cnt++;
		tmp.nextDay();
	}
	int day,month,year;
	char Month[20];
	while(scanf("%d%s%d",&day,&Month,&year)!=EOF)
	{
		for(int i=1;i<13;i++)
		{
			if(strcmp(MonthName[i],Month)==0)
			{
				month=i;
				break;
			}
		}
		int k=buf[year][month][day]-buf[2018][12][31]+1;
		int j=(k%7+7)%7;
		printf("%s",WeekName[j]);
	}
}