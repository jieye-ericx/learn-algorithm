#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n,i;
long long int a,ans;
int main(){
	ios::sync_with_stdio(false);
    while(scanf("%d",&n)!=EOF){
		scanf("%lld",&ans);
		for(i=1;i<n;i++){
			scanf("%lld",&a);
			ans^=a;
		}
		//cout<<ans<<endl;
		if(ans) printf("Win\n");
		else printf("Lose\n");
		

	}
    system("pause");
	return 0;
}
