#include<stdio.h>
#define IsYeap(x) x%100!=0&&x%4==0||x%400==0 ?1:0
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
int buf[5001][13][32];
int Abs(int x)
{
	return x>0?x:-x;
}
void main()
{
	Date tmp;
	int cnt=0;
	tmp.Day=1;
	tmp.Month=1;
	tmp.Year=0;
	while(tmp.Year!=5001)
	{
		buf[tmp.Day][tmp.Month][tmp.Year]=cnt;
		tmp.nextDay();
		cnt++;
	}
	int d1,m1,y1;
	int d2,m2,y2;
	while(scanf("%4d%2d%2d",&d1,&m1,&y1)!=EOF)
	{
		scanf("%4d%2d%2d",&d2,&m2,&y2);
		printf("%d",Abs(buf[y1][m1][d1]-buf[y2][m2][d2])+1);
	}
}