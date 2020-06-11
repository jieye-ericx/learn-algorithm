#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int num;
	int t,x,i;
	vector<int> list;
	cin>>x;
	while(x--){
	
		cin>>t;
		while(t--){
			cin>>num;
			list.push_back(num);
		}
		sort(list.begin(),list.end());
		
		for(i=0;i<list.size();i++)
		{
			cout<<list[i];
			if(i<list.size()-1)cout<<" ";
		}
		cout<<endl; 
		list.clear(); 
	}
	return 0;


}
	
