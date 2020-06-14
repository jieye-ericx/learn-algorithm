#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set> 
using namespace std;
#define N 100002
multiset<int> pp;
struct card{
	int hight;
	int width;
}; 
card Ali[N],Bob[N];

bool cmp(card & a,card &b){
	if(a.hight>b.hight) return 0;
	else if(a.hight<b.hight) return 1;
	else if(a.width>b.width) return 0;
	else return 1;
}
int main(){
	ios::sync_with_stdio(false);
	int t,n,h,w,i,j,ad,ag,bd,bg,sum;
	//cin>>t;
	scanf("%d",&t);
	while(t--){
		ad=0;ag=0;bd=0;bg=0;sum=0;pp.clear();
		memset(Ali,0,sizeof(card)*N);
		memset(Bob,0,sizeof(card)*N);
		//////////////////
		//cin>>n;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d%d",&h,&w);
			Ali[i].hight=max(h,w);
			Ali[i].width=min(h,w);
		}	
		for(i=0;i<n;i++){
			scanf("%d%d",&h,&w);
			Bob[i].hight=max(h,w);
			Bob[i].width=min(h,w);
		}
		sort(Ali,Ali+n,cmp);
		sort(Bob,Bob+n,cmp);
		
		//------------------------------
		//for(i=0;i<n;i++){
		//	cout<<Ali[i].hight<<" "<<Ali[i].width<<endl; 
		//	cout<<Bob[i].hight<<" "<<Bob[i].width<<endl; 
		//}
		//------------------------------- 
		/*ad=0;bd=0;ag=n;bg=n;
		while(bd<=bg){
			if(Ali[ad].hight>=Bob[bd].hight
			&& Ali[ad].width>=Bob[bd].width){
				sum++;
				ad++;
				bd++;
			}else 
		}*/
		for(i=0,j=0;i<n;i++){

			for(;j<n;j++){
				
				if(Ali[i].hight>=Bob[j].hight)
				{
					pp.insert(Bob[j].width);
				}else break;
			}
			if(pp.empty()) 
				continue;
			multiset<int>::iterator it = pp.upper_bound(Ali[i].width);
			if(it==pp.begin())
				continue;
			if(*--it<=Ali[i].width){
				sum++;
				pp.erase(it);
			}
		} 
		printf("%d\n",sum);
	}
	return 0;
}


