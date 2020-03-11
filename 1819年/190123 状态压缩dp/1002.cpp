#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1<<30;
int n,i,t,j,s,end;

struct node{
	string name;
	int dead,cost;
}a[50];
struct kode{
	int time,score,pre,now;
}dp[1<<15];

int main(){
	ios::sync_with_stdio(false);
    scanf("%d",&t);
    while(t--){
		memset(dp,0,sizeof(dp));
		//
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>a[i].name>>a[i].dead>>a[i].cost;
		}
		end=1<<n;
		for(s=1;s<end;s++){
			dp[s].score=inf;
			for(i=n-1;i>=0;i--){
				int tem=1<<i;
				if(s&tem){//第i+1个元素如果在第s中状态中被选择的话
					int past=s-tem;
					int st=dp[past].time+a[i].cost-a[i].dead;
					if(st<=) st=0;
					if(st+dp[past].score<dp[s].score){
						dp[s].score=st+dp[past].score;
						dp[s].now=i;
						dp[s].pre=past;
						dp[s].time=dp[past].time+a[i].cost;	
					}			
				}
			}
		}
		
		

	}
    system("pause");
	return 0;
}
