#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int t[1002]={0},w[1002]={0};
int main(){
	ios::sync_with_stdio(false);
	
	int n,i,j,po,cnt;
	while(cin>>n,n){
		////////
		po=0;j=0;cnt=0;
		////////
		
		for(i=0;i<n;i++) cin>>t[i];
		for(i=0;i<n;i++) cin>>w[i];
		
		sort(t,t+n);
		sort(w,w+n);
		
		int tx=0,td=n-1,wx=0,wd=n-1;
		
		while(tx<=td){
			if(t[td]>w[wd]){
				po++;
				td--;
				wd--;
			}else if(t[tx]>w[wx]){
				po++;
				tx++;
				wx++;
			}else if(t[tx]<w[wd]){
				po--;
				tx++;
				wd--;
			}else {
				tx++;
				wd--;
			}
				
			
		}
		//for(i=0;i<n;i++) cout<<t[i]<<" "<<w[i]<<endl;
		//
		/*for(i=0;i<n;i++)//w
		{
			for(;j<n;j++){//tµÄÂí
				//cout<<"i="<<i<<"j="<<j<<" t["<<j<<"]="<<t[j]<<" w["<<i<<"]="<<w[i]<<endl;
				if(t[j]>w[i]){
					po++;
					t[j]=0;
					w[i]=0;
					break;
				}else if(t[j]==w[i]){
					if(t[n-1]>w[n-1]){
					t[j]=0;
					w[i]=0;
					break;	
					}	
				}else
					continue;
			}
		}
		for(i=0;i<n;i++){
			if(t[i]!=0)cnt++;
		}
		if(po-cnt<=0) cout<<"0"<<endl;
		else {
			//cout<<"po="<<po<<" cnt="<<cnt<<endl; */
			printf("%d\n",po*200);
		}
	
	
	return 0;
}


