#include<stdio.h>
#include<algorithm>
using namespace std;
struct goods
{
	double weight;
	double price;
	double rate;
	bool operator<(const goods & a)const
	{
		return rate<a.rate;
	}
}food[100];
void main()
{
	double n;
	int m;
	while(scanf("%lf%d",&n,&m)!=EOF)
	{
		if(m==-1&&n==-1)break;
		for(int i=0;i<m;i++)
		{
			scanf("%lf%lf",&food[i].weight,&food[i].price);
			food[i].rate=food[i].weight/food[i].price;
		}
		sort(food,food+m);
		int idx=m-1;
		double sum=0;
		while(n>0&&idx>=0)
		{
			if(n>food[idx].price)
			{
				n-=food[idx].price;
				sum+=food[idx].weight;
				idx--;
			}
			else
			{
				sum+=food[idx].weight*n/food[idx].price;
				n=0;
			}
		}
		printf("%.3lf",sum);
	}
}