/*
1314 % 7= 5
1314= £®£®1*10+3£©*10+1£©*10+4
À˘“‘”–
1314 % 7= (((1 * 10 % 7 +3 )*10 % 7 +1)*10 % 7 +4)%7

*/
#include<iostream>

#include<string.h>

using namespace std;

const int MAX=100010;

 

 

int main()

{

	char str[MAX];

	int s,len,sum;

	while(scanf("%s%d",str,&s)!=EOF)

	{

		len=strlen(str);

		sum=0;

		for(int i=0;i<len;i++)

		sum=(sum*10+(str[i]-'0')%s)%s;

		cout<<sum<<endl;

	}

	return 0;

}
