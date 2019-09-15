#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int N;
int n,i,t,j,k;
long long int xyz;
int main(){
	ios::sync_with_stdio(false);
    xyz=0;
    for(N=1;N<100;N++)
    for(i=1;i<=N/2+1;i++){
        if(N%i) continue;
        for(j=1;j<=i;j++){
            if(N%j) continue;
            for(k=1;k<=j;k++){
                if(N%k) continue;
                if(i+j+k!=N) continue;
                //xyz=max(xyz,i*j*k);
                if(xyz<i*j*k) xyz=i*j*k;
                cout<<N<<" "<<xyz<<endl;
            }
        }
    }

    system("pause");
	return 0;
}
