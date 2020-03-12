#include<stdio.h>
#include<string.h>

int main(){

	char str[30],s1[20];
	int i,j,len,s,sum1,sum2,flag;

    while(gets(str)!=NULL)

	{
		len=strlen(str);
		sum1=sum2=0; 

		flag=0; 

		for(i=0,j=0;i<len;i++)

		{

			if(str[i]>='a'&&str[i]<='z')  /*如果是小写字母*/

				s1[j++]=str[i];  /*保存在s1中*/

			else if(str[i]==' '&&str[i-1]!='+')   /*判断str[i-1]!='+'是为了避免将 + 当做一个字符串处理*/

			{

				s1[j]='\0'; /*千万不能忘记字符串结束标志*/

				if(!strcmp(s1,"zero")) s=0; 

				else if(!strcmp(s1,"one")) s=1;

				else if(!strcmp(s1,"two")) s=2;

				else if(!strcmp(s1,"three")) s=3;

				else if(!strcmp(s1,"four")) s=4;

				else if(!strcmp(s1,"five")) s=5;

				else if(!strcmp(s1,"six")) s=6;

				else if(!strcmp(s1,"seven")) s=7;

				else if(!strcmp(s1,"eight")) s=8;

				else if(!strcmp(s1,"nine")) s=9; /*比较字符串，找出代表的数字*/

				j=0;  /*记得从零开始*/

				if(!flag)

					sum1=sum1*10+s; /*sum1保存 + 前面部分代表的数字*/

				else 

					sum2=sum2*10+s; /*sum2保存 + 后面部分代表的数字*/

			}

			else if(str[i]=='+')

				flag=1;  /*标记 + 已出现*/

		}

		if(sum1==0&&sum2==0) /*两个数都是0时结束程序*/

			break; 

		else

		    printf("%d\n",sum1+sum2);

	}

	return 0;

}
