#include <cmath>
#include <cstdio>

long long int f[66]={0};

int main(){
	
	int i,j,t,n;
	
	f[0]=0;f[2]=3;f[1]=1;

        //f[v]=max{f[v],f[v-c[i]]+w[i]}
        for(i=1;i<=64;i++)
        {
        	f[i]=pow(2,i)-1;
		}
	//for(i=3;i<=65;i++)
//	for(j=1;j<=i;j++){
	//	if( f[i]> 2*f[j]+pow(2,i-j)-1 )
	//		f[i]=2*f[j]+pow(2,i-j)-1 ;
//	}
	
	
	//scanf("%d",&t);
	while(scanf("%d",&n)!=-1){
		//scanf("%d",&n);
		//if(n==64) printf("18433\n");
		printf("%lld\n",f[n]);
	}
	return 0;
}


