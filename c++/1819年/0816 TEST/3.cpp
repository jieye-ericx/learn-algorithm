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

char a[10006];int i,t,flag,len,up,down,mid,x,y;
int main(){
	//ios::sync_with_stdio(false);
	sd1(t);getchar();
	while(t--){
		len=0;flag=0;
		scanf("%s",&a);
		len=strlen(a);
		y=a[len-1]-'0';
		for(i=0;i<len-1;i++){
			x=(a[i]-'0');
			if( x%2 ){
				continue;
			}else if(x<y){
			 //b=a[len-1];a[len-1]=a[i];a[i]=b;
			 swap(a[len-1],a[i]);
			 flag=1;
			 break;
			}
		}
		//up=len-1,down=0;
		//while(down<=up){
		//	mid=(up+down)>>1;
			
		//}
		if(flag==1)
			printf("%s\n",a);
  		else
			printf("-1\n");
	}
	return 0;
}


