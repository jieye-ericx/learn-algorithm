#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 1<<15
int k,xd,yd,cnt=1;
int cb[N][N];
void chessBox(int x,int y,int size,int xd,int yd){
	size/=2;
	
	if(xd<x+size&&yd<y+size){//²ÐÈ±ÆåÅÌÔÚ×óÉÏ½Ç 
		chessBox(x,y,size,xd,yd);
		cb[x+size][y+size-1]=cnt;
		cb[x+size][y+size]=cnt;
		cb[x+size-1][y+size]=cnt++;
		
		chessBox(x+size,y,size,x+size,y+size-1);//µÝ¹éÓÒÉÏ½Ç 
		chessBox(x,y+size,size,x+size-1,y+size);	//×óÏÂ½Ç	
		chessBox(x+size,y+size,size,x+size,y+size);//ÓÒÏÂ½Ç 

		
	}else if(xd>=x+size&&yd<y+size){//ÓÒÉÏ½Ç 
		
	}else if(xd<x+size&&yd>=y+size){//×óÏÂ½Ç 
		
	}else {
		
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>k>>xd>>yd; 
	chessBox(0,0,k,xd,yd);
	
	
	return 0;
}

//vfreopen("output.dat","w",) 

