#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;
int main(){
	double x1,x2,y1,y2;
	while(//scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF
	cin>>x1>>y1>>x2>>y2)
	{
		//printf()
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) )<<endl; 
	}
	
	return 0;
} 
