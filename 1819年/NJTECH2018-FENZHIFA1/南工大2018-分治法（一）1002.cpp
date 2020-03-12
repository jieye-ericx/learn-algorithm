#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 100004
int n,k,t,x;
long long sum;
int a[N];

int cmp(int left,int right){

	if(left==right)
		return 0;
	int mid=(left+right)>>1;
	int sum1,sum2;
	sum1=cmp(left,mid);
	cout<<"in cmp("<<left<<","<<right<<")"<<endl;
	cout<<"sum1=cmp("<<left<<","<<mid<<")="<<sum1<<endl;
	sum2=cmp(mid+1,right);
	cout<<"sum2=cmp("<<mid+1<<","<<right<<")="<<sum2<<endl;

	sum+=sum1+sum2;

	int i,j;

	//for(i=mid;i>0;i--){
		//for(j=mid+1;j<=right;j++){
			if(a[mid]-a[mid+1]<=k){
				//cout<<"because a["<<j<<"]-a["<<i<<"]="<<a[j]-a[i]<<" so sum++="<<sum<<endl;
				 sum++;
			}
	//	}
	//}
	cout<<endl;
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&t);
	while(t--){

		sum=0;
		scanf("%d%d",&n,&k);
		for(x=0;x<n;x++){
			scanf("%d",&a[x]);
		}
		sort(a,a+n);

		printf("%lld\n",cmp(0,n-1));
	}
	return 0;
}



#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[100005];

int main()

{

	ll  t;

	ll i,j;

	scanf("%lld",&t);

	while(t--)

	{

		ll n,k;

		scanf("%lld%lld",&n,&k);

		for(i=0;i<n;i++){

			scanf("%lld",&a[i]);

		}

		sort(a,a+n);

		ll ans=0;

		for(i=0,j=0;i<n;i++){

			while(a[j+1]-a[i]<=k && j+1<n)//每次从当前的i位置开始向后找

				j++;

			ans+=j-i;

		}

       // 	for(i=0;i<n;i++){

		//	int pos=i;

		//	for(j=pos;a[j+1]-a[i]<=k && j<n-1;j++)

		//	{}

		//	ans+=j-i;

		//}  换成for之后一直超时。。。

		cout<<ans<<endl;

	}

	return 0;

}

