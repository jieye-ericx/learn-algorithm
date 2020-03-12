#include <iostream>
int main(){
	for(int i=1;i<=18;i++)
	std::cout<<i<<"Ëê"<<" "<<00+i<<".6.17"<<std::endl;
}
/*
#include <stdio.h>

int leapyear(int year)
{
if(year%4==0 && year%100!=0 || year%400==0) return 1;
else return 0;
}

int main()
{

	int t,y,year,month,day;
	int sum=0;
	scanf("%d",&t);

	while(t--){
		scanf("%d-%d-%d",&year,&month,&day);
		
		if( month==2 && day==29) 
			printf("-1\n");
		else{
			sum=0;
			if(month>=3)
				for(y=year+1;y<=year+18;y++)  
					if(leapyear(y)) sum+=366;
					else sum+=365;
			else if(month<=2)           
			{
				for(y=year;y<=year+17;y++) 
				if(leapyear(y)) sum+=366;
				else sum+=365;
			
			}
		printf("%d\n",sum);
	}
	
}
return 0;
}*/
