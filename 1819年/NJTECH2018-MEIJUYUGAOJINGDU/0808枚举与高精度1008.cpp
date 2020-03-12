#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;
char pen;
int width,up,down,bo;
long long int h;
int main(){
	ios::sync_with_stdio(false);
	int n,n_cpy,i,j;cin>>n;
	n_cpy=n;
	while(n_cpy--){
		width=0;up=0;down=0;bo=0;
		
		cin>>pen>>h;
		width=1+h/6;
		if(h%2==0){
			up=h/2-1;
			down=h/2+1;
			bo=h/2-1;
			 
		}else {
			up=h/2;
			down=h/2+1;
			bo=h/2-1;
			 
		}
		
		for(i=0;i<width;i++){
			cout<<" ";
		}
		for(i=0;i<bo;i++){
			cout<<pen;	
		}cout<<endl;
		
		for(i=0;i<up-1;i++){
			for(j=0;j<width;j++){
				cout<<pen;
			}
			for(j=0;j<bo;j++){
			cout<<" ";	
			}
			for(j=0;j<width;j++){
				cout<<pen;
			}
			cout<<endl;
		}
		
		for(i=0;i<width;i++){
			cout<<" ";
		}
		for(i=0;i<bo;i++){
			cout<<pen;	
		}cout<<endl;
		
		for(i=0;i<down-2;i++){
			for(j=0;j<width;j++){
				cout<<pen;
			}
			for(j=0;j<bo;j++){
			cout<<" ";	
			}
			for(j=0;j<width;j++){
				cout<<pen;
			}
			cout<<endl;
		}
		
		for(i=0;i<width;i++){
			cout<<" ";
		}
		for(i=0;i<bo;i++){
			cout<<pen;	
		}cout<<endl;
		
		
		if(n_cpy!=0)cout<<endl; 
	}
	return 0;
}


