/*
��һ���ռ��ڷ�n������������ռ��������

����һ����ȡȫ���еĺ���
int a[]={1.2.3.4.5.6.7};
do{
for(int i=0;i<4;i++)
printf("&d",a[i])
}while(next_permutation(a,a+4))
*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

#define N 15
#define PI 3.14159 
struct point{
	int x,y,z;
}bo[N],ul,rd;
int main(){
	ios::sync_with_stdio(false);
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int n,i,j;
	double ra,dis,ras[N],ret=0,reT=0;
	cin>>n;
	cin>>ul.x>>ul.y>>ul.z;//���ϱ߽����� 
	cin>>rd.x>>rd.y>>rd.z; //���±߽����� 
	
	for(i=0;i<n;i++){
		cin>>bo[i].x>>bo[i].y>>bo[i].z;
	}

	do{
		reT=0;
		for(i=0;i<n;i++)
		{
		ra = min(rd.x-bo[a[i]].x,bo[a[i]].x-ul.x);
		ra = min(ul.y-bo[a[i]].y,bo[a[i]].y-rd.y);
		ra = min(ul.z-bo[a[i]].z,bo[a[i]].z-rd.z);
		for(j=0;j<i;j++)
		{
			dis=sqrt( (bo[a[i]].x-bo[a[j]].x)*(bo[a[i]].x-bo[a[j]].x)+
	    	    	  (bo[a[i]].y-bo[a[j]].y)*(bo[a[i]].y-bo[a[j]].y)+
					  (bo[a[i]].z-bo[a[j]].z)*(bo[a[i]].z-bo[a[j]].z)
					);
			dis-=ras[j];			
			ra=max(0.0,min(ra,dis));
		}
		ras[i]=ra;
		reT+=4.0/3*PI*ra*ra*ra;
		}
		ret=max(ret,reT);
	}while(next_permutation(a,a+4));
	
	cout<<ret<<" "<<reT<<endl;
	
	system("pause");
	return 0;
}


