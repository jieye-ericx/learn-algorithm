#include <iostream>
using namespace std;

int main(){
	int a,b,cnt=0;
	while(cin>>a>>b&&a!=0&&b!=0)
	{
		for(int c=a*100;c<a*100+100;c++)
			if(c%b==0)
			{
				if(c%100>=10)
				{
					if(cnt)cout<<" ";
					cout<<c%100;
					cnt++;
				}
				else 
				{
					if(cnt)cout<<" ";
					cnt++;
					cout<<"0"<<c%100;
				}
			}
		cnt=0;
		cout<<endl;
	}
} 
