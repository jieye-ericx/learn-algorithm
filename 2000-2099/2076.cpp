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

			if(str[i]>='a'&&str[i]<='z')  /*�����Сд��ĸ*/

				s1[j++]=str[i];  /*������s1��*/

			else if(str[i]==' '&&str[i-1]!='+')   /*�ж�str[i-1]!='+'��Ϊ�˱��⽫ + ����һ���ַ�������*/

			{

				s1[j]='\0'; /*ǧ���������ַ���������־*/

				if(!strcmp(s1,"zero")) s=0; 

				else if(!strcmp(s1,"one")) s=1;

				else if(!strcmp(s1,"two")) s=2;

				else if(!strcmp(s1,"three")) s=3;

				else if(!strcmp(s1,"four")) s=4;

				else if(!strcmp(s1,"five")) s=5;

				else if(!strcmp(s1,"six")) s=6;

				else if(!strcmp(s1,"seven")) s=7;

				else if(!strcmp(s1,"eight")) s=8;

				else if(!strcmp(s1,"nine")) s=9; /*�Ƚ��ַ������ҳ����������*/

				j=0;  /*�ǵô��㿪ʼ*/

				if(!flag)

					sum1=sum1*10+s; /*sum1���� + ǰ�沿�ִ��������*/

				else 

					sum2=sum2*10+s; /*sum2���� + ���沿�ִ��������*/

			}

			else if(str[i]=='+')

				flag=1;  /*��� + �ѳ���*/

		}

		if(sum1==0&&sum2==0) /*����������0ʱ��������*/

			break; 

		else

		    printf("%d\n",sum1+sum2);

	}

	return 0;

}
