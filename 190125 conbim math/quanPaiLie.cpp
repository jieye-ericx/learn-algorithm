#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 50005
void p(int *x,int l,int r){
    if(l==r){
        for(int i=l,i<=r;i++)
            cout<<x[l]<<" ";
        cout<<endl;
        return;
    }
    for(int i=l;i<=r;i++){
        swap(x,i,l);
        p(x,l+1,r);
    }

}
int main(){
    scanf("%d",&t);
	while(t--){
		
    system("pause");
	return 0;
}
