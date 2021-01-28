#include<stdio.h>
#include<stack>
using namespace std;
stack<int> op,in;
int compare[5][5]=
{
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0
};
char str[100];
void getop(bool &reto,int &retn,int &i)
{
	if(i==0&&op.empty()==true)
	{
		reto=true;
		retn=0;
		return;
	}
	if(str[i]==0)
	{
		reto=true;
		retn=0;
		return;
	}
	if(str[i]>='0'&&str[i]<='9')
	{
		reto=false;
	}
	else
	{
		reto=true;
		if(str[i]=='+')retn=1;
		else if(str[i]=='-')retn=2;
		else if(str[i]=='*')retn=3;
		else if(str[i]=='/')retn=4;
		i+=2;
		return;
	}
	retn=0;
	for(;str[i]!=' '&&str[i]!=0;i++)
	{
		retn*=10;
		retn+=str[i]-'0';
	}
	if(str[i]=' ')i++;
	return;
}
void main()
{
	while(gets(str))
	{
		if(str[0]=='0'&&str[1]==0)break;
		bool retop;
		int retnp;
		int idx=0;
		while(in.empty()==false)in.pop();
		while(op.empty()==false)op.pop();
		while(true)
		{
			getop(retop,retnp,idx);
			if(retop==false)
			{
				in.push(retnp);
			}
			else
			{
				if(op.empty()==true||compare[retnp][op.top()]==1)
				{
					op.push(retnp);
				}
				else
				{
					while(compare[retnp][op.top()]==0)
					{
						int a=in.top();
						in.pop();
						int b=in.top();
						in.pop();
						int ret=op.top();
						op.pop();
						if(ret==1)in.push(b+a);
						else if(ret==2)in.push(b-a);
						else if(ret==3)in.push(b*a);
						else if(ret==4)in.push(b/a);
					}
					op.push(retnp);
				}
			}
			if(op.size()==2&&op.top()==0)break;
		}
		printf("%d",in.top());
	}
}
