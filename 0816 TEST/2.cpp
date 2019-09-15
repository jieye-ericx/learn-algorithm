#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define sd1(a) scanf("%d",&a)
#define slld1(a) scanf("%lld",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pd1(a) printf("%d\n",a)
#define plld1(a) printf("%lld\n",a)

int lstr,lsub,i,j,flag,flag1,a[1005],sum;//lsub<=lstr
char str[1005],sub[1005];int mp;
int main(){
	int t;sd1(t);
	while(t--){
		//sum=0;
		///////
		sd2(lsub,lstr);
		cin>>sub;
		cin>>str;
		sum=lstr;
		for(i=0;i<=lstr-lsub;i++){
			flag=0;
			for(j=0;j<lsub;j++){
			
				if(str[i+j]==sub[j]){
					continue;
				}
				flag++;
			}
			if(flag<sum){
				sum=flag;
				mp=i;
			}
		}
		if(sum==0) {
			printf("0");
		}else {
			pd1(sum);
	
			flag1=0;
			for(i=mp,j=0;j<lsub;j++)
			{
				if(str[i+j]!=sub[j]){
					
					if(flag1==1) printf(" ");
					printf("%d",j+1);
					flag1=1;
				}
			}
		}
		if(t!=0)	printf("\n");
		



	}
	return 0;
}


