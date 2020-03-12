#include<stdio.h>

long long int compute(int h)
{
	if(h>0)
	return h*compute(h-1);
	return 1;
} 
long long int compute1(int t)
{
 	if(t>3)
 	return (t-1)*(compute1(t-1)+compute1(t-2));
 	if(t==1||t==2)
		return 1;
	if(t==3)
	return 2;
	if(t==0)
	return 0;
}

int main()
{
	
	int t,n,m;long long int outcome;
	scanf("%d",&t);
		while(t--)
			{
				scanf("%d%d",&n,&m);
				outcome=compute(n)/(compute(n-m)*compute(m))*compute1(m);
				printf("%lld\n",outcome);
			}
	
	
	return 0;
}
