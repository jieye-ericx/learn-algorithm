#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 202
int a[N];//��ʼ��ͬmemset(b,0,sizeof(b)) Ҳ���Գ�ʼ��Ϊ-1;
int main(){
	ios::sync_with_stdio(false);
	
	int n,m;int i;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>t;
		a[t]=1;
	}
	for(i=0;i<n;i++) {
		if(a[i]==0){
			b[cnt]++;
			flag=1;
		}else{
			if(flag)
				cnt++;
			flag=0;
		} 
	}
	if(a[n-1]==0) cnt++;
	sort(b,b+cnt,greater<int>()); 
	
	return 0;
}


