#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n) ){
	
	long long int array[32]={0};
	
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&array[i]);
	}
	long long int max=array[0];
	for(int x=0;x<n;x++)
	{
		if(array[x]==0)array[x]=1;
		if(array[x]>max)max=array[x];
	}
	int cnt=0;
	for(long long int y=1;1;y++)
	{
		for(int m=0;m<n;m++)
		{
			if(max*y%array[m]!=0){cnt=0;break;}
			cnt++;
		}
		if(cnt==n)
		{
			printf("%lld\n",max*y);
			break; 
		}
	}
}
 } 
