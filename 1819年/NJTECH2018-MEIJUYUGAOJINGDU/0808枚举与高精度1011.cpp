#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>a(2007);
vector<int>a_1(2007);
vector<int>a_2(2007);
vector<int>a_3(2007);
vector<int>a_4(2007);
int len;
void cmp(vector<int> & a,vector<int> & b){
	int i;
	for(i=0;i<=len-1;i++){
		
		a[i]+=b[i];
		if(a[i]>9){
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	}
	/*cout<<"a[len-3="<<len-3<<"]="<<a[len-3]<<endl;
	cout<<"a[len-2="<<len-2<<"]="<<a[len-2]<<endl;
	cout<<"a[len-1="<<len-1<<"]="<<a[len-1]<<endl;
	cout<<"a[len  ="<<len<<"]="<<a[len]<<endl;*/ 
	if(a[len]){	
		len++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n,i,j,cnt=0;
	while(cin>>n){
		len=1;

		if(n<5){
			cout<<"1"<<endl;
		} else{
			cnt=0;
			a.assign(2007,0);
			a_1.assign(2007,0);
			a_2.assign(2007,0);
			a_3.assign(2007,0);
			a_4.assign(2007,0);
			a_1[0]=1;a_2[0]=1;a_3[0]=1;a_4[0]=1;

			while(n-->=5){
				cmp(a,a_1);
				cmp(a,a_2);
				cmp(a,a_3);
				cmp(a,a_4);
				
				a_4=a_3;
				a_3=a_2;
				a_2=a_1;
				a_1=a;
				//cout<<endl;
				for(i=0;i<a.size()-1;i++){
					a[i]=0;
				}
			}
			for(j=len-1;j>=0;j--){
				cout<<a_1[j];
			}
			cout<<endl;
		}
	} 
	return 0;
}


