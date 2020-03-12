//20180717 2000 whka
//����������������������������������������
/*#include <iostream>
using namespace std;

int main(){
	char array[3][3];
	for(int x=0;x<3;x++)
	for(int y=0;y<3;y++)
	cin>>array[x][y];
	char mid;
	for(int i=0;i<3;i++)
	//for(int j=0;j<3;j++)
	{
		if(array[i][0]>array[i][1]) mid=array[i][0],array[i][0]=array[i][1],array[i][1]=mid;  

 		if(array[i][0]>array[i][2]) mid=array[i][0],array[i][0]=array[i][2],array[i][2]=mid;

 		if(array[i][1]>array[i][2]) mid=array[i][1],array[i][1]=array[i][2],array[i][2]=mid;
			
	}
	for(int i=0;i<3;i++)
		cout<<array[i][0]<<" "<<array[i][1]<<" "<<array[i][2]<<endl; 
	
	return 0;
} */


#include<stdio.h>

int main(){

char a,b,c,d;

while(scanf("%c%c%c",&a,&b,&c)!=EOF)

//�Ӽ����ж�ȡ�ַ���ÿ����һ�飬������λ�á�

//�ո���Ա���س��Ķ��롣

{

//��ʼ����

 if(a>b) {
	 d=a,a=b,b=d;  
 }

 if(a>c) {d=a,a=c,c=d;}

 if(b>c) {d=b,b=c,c=d;}

 printf("由小到大%c %c %c\n",a,b,c);

}

}
