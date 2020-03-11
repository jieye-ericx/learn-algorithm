#include<cstdio>
#include<string.h>
int main()
{
	char a[100];
	int t,d,i,num1,num2,num3,num4,num5;
	scanf("%d",&t);
	getchar();
		
			 
			while(gets_s(a)&&t--)
			{
				
				num1=0;num2=0;num3=0;num4=0;num5=0;
				d=strlen(a);
				for(i=0;i<d;i++)
					{  
					if(a[i]=='a')num1++;
					if(a[i]=='e')num2++;
					if(a[i]=='i')num3++;
					if(a[i]=='o')num4++;
					if(a[i]=='u')num5++;
  					}
				printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",num1,num2,num3,num4,num5);
				if(t>0)printf("\n");
			}
			
		
	
	return 0;
}
