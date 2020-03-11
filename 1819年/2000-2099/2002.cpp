
#include <iostream>
using namespace std;

int main(){
	int r;
	while(scanf("%d",&r)!=EOF)
	{
		if(r>100||r<0)cout<<"Score is error!"<<endl;
		if(r>=90&&r<=100)cout<<"A"<<endl;
		if(r>=80&&r<=89)cout<<"B"<<endl;
		if(r>=70&&r<=79)cout<<"C"<<endl;
		if(r>=60&&r<=69)cout<<"D"<<endl;
		if(r>=0&&r<=59)cout<<"E"<<endl;
	}
	
	return 0;
} 
