#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(){
	
	int n,m,t;
	vector<int> num;
	while(scanf("%d%d",&n,&m)!=-1){
	num.clear();
	while(n--){
		scanf("%d",&t);
		num.push_back(t);
	}
	sort(num.begin(),num.end(),greater<int>());
	for(int i=0;i<m;i++)
	{
		printf("%d",num[i]);
		if(i<m-1)printf(" ");
	}
	printf("\n");
}
	return 0;
}

