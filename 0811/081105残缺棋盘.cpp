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
	
	if(xd<x+size&&yd<y+size){//��ȱ���������Ͻ� 
		chessBox(x,y,size,xd,yd);
		cb[x+size][y+size-1]=cnt;
		cb[x+size][y+size]=cnt;
		cb[x+size-1][y+size]=cnt++;
		
		chessBox(x+size,y,size,x+size,y+size-1);//�ݹ����Ͻ� 
		chessBox(x,y+size,size,x+size-1,y+size);	//���½�	
		chessBox(x+size,y+size,size,x+size,y+size);//���½� 

		
	}else if(xd>=x+size&&yd<y+size){//���Ͻ� 
		
	}else if(xd<x+size&&yd>=y+size){//���½� 
		
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

