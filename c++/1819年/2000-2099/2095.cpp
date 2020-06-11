/*#include <stdio.h>
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		int p[1000000];
		for(int x=0;x<n;x++)
			scanf("%d",&p[x]);
		for(int y=0;y<n;y++)
		{
			int cnt=0;
			for(int h=0;h<n;h++)
			{
				if(p[h]==p[y]&&h!=y)break;
				cnt++;	
			}
			if(cnt==n){
			printf("%d\n",p[y]);
			break;
			}
		}
	}
	return 0;
}
*/

#include <stdio.h>
int main(){
	int n;int num1,num2;
	while(~scanf("%d",&n)&&n){
		num2=0;
		while(n--){
			scanf("%d",&num1);
			num2^=num1;
		}
		printf("%d\n",num2);
	}
	return 0;
}

