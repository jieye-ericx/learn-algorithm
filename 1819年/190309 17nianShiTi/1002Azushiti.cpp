#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<stack>
using namespace std;

//1========================================
//int map[10][10];
//int avi[10][10];//0表示没走过,1表示能走通,2表示走不通
//int dir[4][2]={-1,0,0,1,1,0,0,-1};
//int i,j,k;
//char s;
//bool dfs(int x,int y,int dep){
//	if(dep>102){
//		return false;
//	}
//	int i,dx,dy;
//	i=map[x][y]-1;
//	dx=x+dir[i][0];
//	dy=y+dir[i][1];
//	if(dx<0||dy<0||dy>9||dx>9){
//		//avi[dx][dy]=1;
//		//avi[x][y]=1;
//		return true;
//	}
//	dfs(dx,dy,dep+1);
////	if(avi[dx][dy]==1) {
////		avi[x][y]=1;
////		return;
////	}
////	else if(avi[dx][dy]==2) {
////		avi[x][y]=2;
////		return;
////	}
////	else {
////		dfs(dx,dy,dep+1);
////	}

//}

//2======================================
//int cnt,i,j,k,sum;
//string a,t1,t2,t3,t4;
//queue<string> q;
//set<string> s;
//string ope(int t,int x,string aaa){
//	char s;
//	int b;
//	string am=aaa;
//	switch(t){
//		case 1:
//			b=(x+8)%9;
//			am[x]=am[b];
//			am[b]='0';
//			return am;
//			break;
//		case 2:
//			b=(x+7)%9;
//			am[x]=am[b];
//			am[b]='0';
//			return am;
//			break;
//		case 3:
//			b=(x+10)%9;
//			am[x]=am[b];
//			am[b]='0';
//			return am;
//			break;
//		case 4:
//			b=(x+11)%9;
//			am[x]=am[b];
//			am[b]='0';
//			return am;
//			break;
//	}
//}
//void dfs(string ss,int dep){
//	//cout<<ss<<endl;
////	if(dep>3) return;
//	if(ss=="087654321"){
//		sum=min(sum,dep);
//		return;
//	}
//	//执行插入四种情况
//		for(i=0;i<9;i++){
//        	if(ss[i]=='0') {
//				t1=ope(1,i,ss);
//				t2=ope(2,i,ss);
//				t3=ope(3,i,ss);
//				t4=ope(4,i,ss);
//				cout<<endl<<t1<<endl<<t2<<endl<<t3<<endl<<t4<<endl;
//				if(!s.count(t1)){
//					//q.push(t1);
//					s.insert(t1);
//					dfs(t1,dep+1);
//				}
//				if(!s.count(t2)){
//					//q.push(t2);
//					s.insert(t2);
//					dfs(t2,dep+1);
//				}
//				if(!s.count(t3)){
//					//q.push(t2);
//					s.insert(t3);
//					dfs(t3,dep+1);
//				}
//				if(!s.count(t4)){
//					//q.push(t4);
//					s.insert(t4);
//					dfs(t4,dep+1);
//				}
//			}
//		}
//}
//07正则问题============================
//string str;
//int p=0;
//
//int fun(){
//	int a=0,b=0;
//	while(p<str.size()){
//		
//		if(str[p]=='x'){
//			b++;
//			p++;
//		}else if(str[p]=='|'){
//			p++;
//			a=max(a,b);
//			b=0;
//		}else if(str[p]=='('){
//
//		}else if(str[p]==')'){
//
//		}
//	}
//	return max(a,b);
//}
string s,ao;
int cnt;
	
int main(){
	//1
//	memset(avi,0,sizeof(avi));
//	memset(map,0,sizeof(map));
//	for(i=0;i<10;i++){
//		for(j=0;j<10;j++){
//			cin>>s;
//			if(s=='U') map[i][j]=1;
//			else if(s=='R') map[i][j]=2;
//			else if(s=='D') map[i][j]=3;
//			else if(s=='L') map[i][j]=4;
//		}
//	}
//	int sum=0;
//	for(i=0;i<10;i++){
//		for(j=0;j<10;j++){
//			//if(avi[i][j]==0)
//				if(dfs(i,j,0)) sum++;
//		}
//	}
//	cout<<sum;
//
	//2========================================
//	sum=10000000;
//	cnt=0;
//	for(i=0;i<9;i++){
//		a+=i+'0';
//	}
//	s.insert(a);
//	q.push(a);
//	while(!q.empty()){
//		//if(cnt>3) break;
//		a=q.front();
//		if(a=="087654321"){
//			sum=min(cnt,sum);
//   		}
//		q.pop();
//		//执行插入四种情况
//		for(i=0;i<9;i++){
//        	if(a[i]=='0') {
//        		cnt++;
//				t1=ope(1,i);
//				t2=ope(2,i);
//				t3=ope(3,i);
//				t4=ope(4,i);
//				//cout<<endl<<t1<<endl<<t2<<endl<<t3<<endl<<t4<<endl;
//				if(!s.count(t1)){
//					q.push(t1);
//					s.insert(t1);
//				}
//				if(!s.count(t2)){
//					q.push(t2);
//					s.insert(t2);
//				}
//				if(!s.count(t3)){
//					q.push(t2);
//					s.insert((t3));
//				}
//				if(!s.count(t4)){
//					q.push(t4);
//					s.insert((t4));
//				}
//			}
//		}
//	}
//	cout<<sum;
//---------------------------------------------
//	sum=10000000;
//	cnt=0;
//	s.clear();
//	for(i=0;i<9;i++){
//		a+=i+'0';
//	}
//	s.insert(a);
//	dfs(a,0);
//	cout<<sum;

//07正则问题=========================
	while(cin>>s){
		cnt=0;
		ao.clear();
		for(int i=0;i<s.size();i++){
			if(s[i]!='x') {
				if(cnt) ao+=(cnt+'0');
				ao+=s[i];
				cnt=0;
			}
			else cnt++;
			if(i==s.size()-1)
				if(cnt)
					ao+=(cnt+'0');
		}
		cout<<ao<<"\n";
		stack<int> sta1;
		stack<char> sta2;
		int t1,t2;
		for(int i=0;i<ao.size();i++){
			if(ao[i]=='('||ao[i]=='|'){
				sta2.push(ao[i]);
			}else if(ao[i]==')'){
				if(sta2.top()=='|'){
					t1=sta1.top(),sta1.pop();
					t2=sta1.top(),sta1.pop();
					sta2.pop();
					sta2.pop();
				}else{
					sta2.pop();
					if(){//
						
					}else if(sta2.top()=='|'||sta2.top()=='('){//左边没有
					    if( !(ao[i+1]-'0'>=1&&ao[i+1]-'0'<=9) ){
					    	
						}//右边没有
						else{
							
						}
						
					}
				}
				
				t1=max(t1,t2);
				if(ao[i+1]-'0'>=1&&ao[i+1]-'0'<=9){
					t1+=(ao[i+1]-'0');
					i++;
				}
				sta1.push(t1);
			}else{
				sta1.push(ao[i]-'0');
				if(i==ao.size()-1){
					t1=sta1.top(),sta1.pop();
					if(!sta1.empty()){
						t2=sta1.top(),sta1.pop();
					}else{
						t2=-1;
					}
					if(!sta2.empty()) sta2.pop();
					t1=max(t1,t2);
					sta1.push(t1);
				}
			}

		}
//		cout<<sta1.size()<<"\n\n";
		int sum=0;
		if(sta2.empty()){
			while(!sta1.empty()){
			sum+=sta1.top();
			sta1.pop();
			}
		}else{
			sum=sta1.top();
			sta1.pop();
			sum=max(sum,sta1.top());
		}
		
		cout<<sum<<endl;
	}
	//xx|xx(xx|x)xx
	system("pause");
	return 0;
}
