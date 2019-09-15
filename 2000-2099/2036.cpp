#include <stdio.h>
int main(){
	int n;int x1,x2,x3,y1,y2,y3;double S=0;
	while(scanf("%d",&n)!=EOF&&n<=100&&n>=3){
		int n_cnt=n;
		scanf("%d%d",&x1,&y1);
		scanf("%d%d",&x2,&y2);
		while(n_cnt-2>0){
		
		scanf("%d%d",&x3,&y3);
		S+=0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
		
		n_cnt--;
		x2=x3;y2=y3; 
		}
		printf("%.0lf\n",S);
		S=0;
	}
	return 0;
}


