#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int main()
{
	char str[100];
	cin>>str;
	string a=str;
	for(int i=0;i<a.size();i++)
	{
		a[i]=tolower(a[i]);
	}
	while(gets(str))
	{
		string b=str;
		string c=str;
		for(i=0;i<c.size();i++)
		{
			c[i]=tolower(c[i]);
		}
		size_t t=c.find(a,0);
		while(t!=string::npos)
		{
			b.erase(t,a.size());
			c.erase(t,a.size());
			t=c.find(a,t);
		}
		t=b.find(' ',0);
		while(t!=string::npos)
		{
			b.erase(t,1);
			t=b.find(' ',t);
		}
		cout<<b<<endl;
	}
	return 0;
}