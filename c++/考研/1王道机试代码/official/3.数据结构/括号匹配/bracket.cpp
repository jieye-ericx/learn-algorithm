#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S;
char str[110];
char ans[110];
void main()
{
	while(scanf("%s",str)!=EOF)
	{
		while(S.empty()==false)S.pop();
		for(int i=0;str[i]!=0;i++)
		{
			if(str[i]=='(')
			{
				S.push(i);
				ans[i]=' ';
			}
			else if(str[i]==')')
			{
				if(S.empty()==false)
				{
					S.pop();
					ans[i]=' ';
				}
				else ans[i]='?';
			}
			else ans[i]=' ';
		}
		while(S.empty()==false)
		{
			ans[S.top()]='$';
			S.pop();
		}
		printf("%s\n",str);
		printf("%s\n",ans);
	}
}