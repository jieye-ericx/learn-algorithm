
#include <stdio.h>
int main(){
	int year,month,day,days=0;
	int daysArray[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char a,b;
	while(scanf("%d%c%d%c%d",&year,&a,&month,&b,&day)!=EOF)
	{
		if(year%4==0&&year%100!=0||year%400==0)daysArray[1]=29;
		for(int i=0;i<month-1;i++)
			days+=daysArray[i];
		days+=day;
		daysArray[1]=28;
		printf("%d\n",days);
		days=0;
	}
}
