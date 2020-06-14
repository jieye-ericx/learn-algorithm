#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

void print(int a,int step){
    if(step==8){
        return;
    }
    print(a/2,step+1);
    // cout<<a%2;
    if(a%2) cout<<"@";
    else cout<<" ";
}

int main(){
    int i,j,a;
    // freopen("2.in","r",stdin);
    // freopen("2.out","w",stdout);
    for(i=0;i<10;i++){
        for(j=0;j<16;j++){
            cin>>a;
            if(a<0){
                a=(a^255)+1;
            }
            print(a,1);
            cin>>a;
            if(a<0){
                a=(a^255)+1;
            }
            print(a,1);
            cout<<endl;
        }
        cout<<endl;
    }
    system("pause");
	return 0;
}
