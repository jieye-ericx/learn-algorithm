// 5 3
// 7 2
// 4 3
// 5 2
//13.333
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
//************************
//利用
//cout.setf(ios::left);//左对齐 
//cout<<fixed<<setorecision(3)<<ret<<endl;
//cout.setfill('*')<<setw(10)<<1.2<<endl;
//fixed加上后变为三位小数，否则为三位有效数字 
//************************
using namespace std;
#define N 10002
struct node{
	int javabean;
	int catfood;
}rooms[N]; 
int n,m;

bool cmp( node n1, node n2){
	return n1.javabean*n2.catfood>n1.javabean*n1.catfood;
}

int main(){
	ios::sync_with_stdio(false);
	int i; 
	double ret=0;
	while(cin>>m>>n,!(m==-1&&n==-1) ){
	ret=0; 
	
	for(i=0;i<n;i++){
		cin>>rooms[i].javabean>>rooms[i].catfood;
	}
	//-------------------------------------------------
	for(i=0;i<n;i++){
		cout<<"rooms["<<i<<"] "<<rooms[i].javabean<<" "<<rooms[i].catfood<<endl; 
	}
	//------------------------------------------------- 
	sort(rooms,rooms+n,cmp);
	//-------------------------------------------------
	for(i=0;i<n;i++){
		cout<<"rooms["<<i<<"] "<<rooms[i].javabean<<" "<<rooms[i].catfood<<endl; 
	}
	//-------------------------------------------------
	for(i=0;i<n;i++){
		if(m>=rooms[i].catfood){
			ret+=rooms[i].javabean; 
			m-=rooms[i].catfood;
		} 
		else break;
		
	}
	if(i<n){
		ret+=1.0*rooms[i].javabean*m/rooms[i].catfood;
	}
	printf("%.3lf\n",ret);
}
	return 0;
}


