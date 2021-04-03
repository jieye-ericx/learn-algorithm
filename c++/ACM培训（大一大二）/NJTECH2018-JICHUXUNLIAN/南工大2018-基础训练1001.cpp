#include <stdio.h>
int main(){
        int n,lastfloor=0,newfloor=0,time=0;
        while(scanf("%d",&n)!=-1&&n)
        {
        	while(n--){
        		scanf("%d",&newfloor);
        		if(newfloor>lastfloor){
				time+=(newfloor-lastfloor)*6;
				time+=5;
				}
				else
				{
				time+=(lastfloor-newfloor)*4;
				time+=5;
				}
				lastfloor=newfloor;
        	}
        	printf("%d\n",time);
        	time=0;lastfloor=0;
		}
		return 0;
	}
