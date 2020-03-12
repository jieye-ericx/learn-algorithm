#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
using namespace std;

int a[9]={0};
int c[9]={0};
int lowbit(int x){
    return x & (-x);
}
int getsun(int x){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=c[i];
    }
    return ans;
}

// int getsum(int x)
// {
// int ans=0;
// for(int i=x;i>0;i-=lowbit(i))
// ans+=C[i];
// return ans；
// }
int main(){
    for(int i=1;i<=8;i++){
        a[i]=i;
    }
    for(int i=1;i<9;i++){
        c[i]+=a[i-lowbit(i)+1];
    }for(int i=1;i<=8;i++){
        cout<<getsun(i)<<" ";
    }
    //cout<<lowbit(7);



    system("pause");
    return 0;
}