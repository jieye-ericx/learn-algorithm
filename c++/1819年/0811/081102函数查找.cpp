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
	if( binary_search(a,a+10,x) )//二分查找函数 
		cout<<x<<" is in a"<<endl;
	cout<<lower_bound(a,a+10,4)-a<<endl;//返回大于等于四的第一个元素的指针 
	cout<<upper_bound(a,a+10,4)-a<<endl;//返回大于4的第一个元素的指针
	
	//pair<int,int> pa;
	//pa=equal_range(a,a+10,4); 
		
	return 0;
}


