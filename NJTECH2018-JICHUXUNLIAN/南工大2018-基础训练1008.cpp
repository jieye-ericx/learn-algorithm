#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
int orderS[1005]={0};
int maxs=-(1<<30);
map<string,int> score;
set<string> winner;
string orderN[1005];
int main(){
	int n,t,i;
	scanf("%d",&n);
	while(n--){
	
	
	
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		cin>>orderN[i]>>orderS[i];
	}
	for(i=0;i<t;i++)
	{
		score[ orderN[i] ]+=orderS[i];
	}
	map<string,int>::iterator it;
	for(it=score.begin();it!=score.end();it++)
	{
		if(it->second>maxs)
		{
			winner.clear();
			winner.insert(it->first);
			maxs=it->second;
		}
		else if(it->second==maxs)
		{
			winner.insert(it->first);
		}
	}
	score.clear();
	for(i=0;i<t;i++)
	{
		score[orderN[i]]+=orderS[i];
		if(winner.count(orderN[i])&&score[orderN[i]]>=maxs)
			{
			cout<<orderN[i]<<endl;
			break;
		}
	}
		
	winner.clear();
	score.clear();
	maxs=-(1<<30);
}
	
	return 0;
}

