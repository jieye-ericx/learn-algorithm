#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 10002
int n,m;
struct node{
	int len;
	int rob;
}roads[N];
bool cmp(node & a,node & b){
	return a.rob>b.rob;
}
int main(){
	ios::sync_with_stdio(false);
	
	int i,j,sum;
	//////////////
	
	while(~scanf("%d%d",&n,&m),n!=0||m!=0){
		sum=0;
		memset(roads,0,sizeof(roads));
		////////////////////
		for(i=0;i<n;i++){
			scanf("%d%d",&roads[i].len,&roads[i].rob);
		}
		sort(roads,roads+n,cmp);
		
		for(i=0;i<n;i++){
			if(m<=roads[i].len){
				///cout<<"i="<<i<<" m="<<m<<" roads["<<i<<"].lem="<<roads[i].len<<endl;
				roads[i].len-=m;
				break;
			}
			else{
				//cout<<"m>ʱiΪ"<<i<<endl;
				m-=roads[i].len;
			}
		}
		
		for(;i<n;i++){
			//cout<<i<<endl;
			sum+=roads[i].len*roads[i].rob;
		}
		
		printf("%d\n",sum);
	}
	return 0;
}


