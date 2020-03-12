#include <iostream>
using namespace std;  
const int maxn=100;
char s[maxn];
int n,l;
int ans=0;
bool check(char *s1,int len)
{
	//长度 
	for(int i=1;i<=len/2;i++){
		bool flag=0;
		//
		for(int j=len;j>=len-i+1;j--){
			if(s1[j]!=s1[j-i]) {
				flag=true;
				break;
			}
		} 
		if(flag==0)return false;//这里为先检验长度为1的字符子串，然后是2，3，。。。
        
	} 
	return true;
}
void dfs(int cur)
{
	if(ans==n){
		
		for(int i=1;i<cur;i++){
			cout<<s[i];
			if(i%64==0&&i!=(cur-1)){
				cout<<endl;
				continue;
			}
			if(i%4==0&&i!=(cur-1))cout<<" ";
		}
		cout<<endl;
		cout<<cur-1<<endl;
	}
	if(ans>n)return; 
	for(int i=1;i<=l;i++){
		char cur_c=i+'A'-1;
		s[cur]=cur_c;
		if(check(s,cur)){
			ans++;
//			cout<<"递归 "<<cur_c<<endl;
			dfs(cur+1);
		}
	}
}
int main()  
{
	while(cin>>n>>l){
		ans=0;
		if(n==0&&l==0)break;
		dfs(1);
	}
	return 0; 
} 
