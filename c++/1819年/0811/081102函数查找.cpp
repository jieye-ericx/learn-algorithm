#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int a[]={1,2,3,4,4,4,4,5,7,9},x=7;
	if( binary_search(a,a+10,x) )//���ֲ��Һ��� 
		cout<<x<<" is in a"<<endl;
	cout<<lower_bound(a,a+10,4)-a<<endl;//���ش��ڵ����ĵĵ�һ��Ԫ�ص�ָ�� 
	cout<<upper_bound(a,a+10,4)-a<<endl;//���ش���4�ĵ�һ��Ԫ�ص�ָ��
	
	//pair<int,int> pa;
	//pa=equal_range(a,a+10,4); 
		
	return 0;
}


