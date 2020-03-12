#include <stdio.h>

bool judge(int n)
{
	for(int x=2;x*x<=n;x++)
	{
		if(n%x==0)return false;
	}
	return true;
}
int main(){
	int a,cnt=0;
	while(~scanf("%d",&a)&&a)
	{
		
		for(int x=2;x<a/2;x++)
			if(judge(x)&&judge(a-x)) cnt++;
		printf("%d\n",cnt);
		cnt=0;
	}
	return 0;
}


