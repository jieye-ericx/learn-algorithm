#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
long long int a,b,c;
int main(){
    a=1;c=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>b;
            a*=b;
            while(a%10==0){
                c++;
                a/=10;
            }
            if(a>=1000000000){
                a%=1000000000;
            }
        }
    }
    cout<<c;
    system("pause");
	return 0;
}
