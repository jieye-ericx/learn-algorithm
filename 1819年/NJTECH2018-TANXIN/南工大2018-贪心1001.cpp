#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct room{
	int jb;
	int cf;
}rooms[1002];
bool cmp(room & a,room & b){
	return a.jb*b.cf>b.jb*a.cf;
	
}
int n,m;double sum=0;

int main(){
	ios::sync_with_stdio(false);
	int i;
	while(cin>>m>>n&&(n!=-1&&m!=-1)){
		sum=0;
		memset(rooms,0,sizeof(room)*1002);
		
		for(i=0;i<n;i++){
			cin>>rooms[i].jb>>rooms[i].cf;
		}
	sort(rooms,rooms+n,cmp);
	//for(i=0;i<n;i++){
	//		cout<<rooms[i].jb<<" "<<rooms[i].cf<<endl;
	//	}//²âÊÔÓÃÅÅÐòÊý×é
	for(i=0;i<n;i++){
		if(m<rooms[i].cf){
			sum+=(double)rooms[i].jb*m/rooms[i].cf;
			break;
		}else{
			sum+=(double)rooms[i].jb;
			m-=rooms[i].cf;
		}
	}		
	printf("%.3lf\n",sum);	
	}
	return 0;
}


