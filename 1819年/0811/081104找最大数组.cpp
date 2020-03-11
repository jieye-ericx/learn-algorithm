#include <iostream>
#include <algorithm>

using namespace std;

int a[]={6,2,3,4,8,1,10,9};
int len=sizeof(a)/sizeof(int);

void find(int left,int right,int &mx,int &mn){
    int mid=(left+right)>>1,max1,min1,max2,min2;
    find(left,mid,max1,min1);
    find(mid+1,right,max2,min2);
    mx=max(max1,max2);
    mn=min(min1,min2);

}
int main(){
    int mx,mn;
    find(0,len,mx,mn);
    cout<<mx<<" "<<mn<<endl;
}