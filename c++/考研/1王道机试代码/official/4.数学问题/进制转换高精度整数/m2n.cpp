#include<stdio.h>
#include<string.h>
#define maxDiggits 100;
struct bigInteger
{
	int digit[maxDigits];
	int size;
	void init()
	{
		for(int i=0;i<1000;i++)digit[i]=0;
		size=0;
	}
	void set(int x)
	{
		init();
		int tmp;
		while(x!=0)
		{
			tmp=digit[size++]%10000;

		}
	}
}