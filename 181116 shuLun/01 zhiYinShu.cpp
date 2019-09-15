#include <iostream>

using namespace std;
//a[i][0]//第i个质数，以及它的指数
int cf(int n,int a[100][2]){
    int i,cnt;
    for(i=0;i<=n;i++){
        while(n%i==0){
            a[cnt][0]=i;
            a[cnt][1]++;
            n/=i;
        }
    }
}
//欧几里得辗转相除法
int gcd(int a,int b){
    if(b==0) return a;
    
    int tmp;
    while(b!=0){
    tmp=a;
    a=b;
    b=tmp%b;
    }
    return a;
    
}
//或者递归
int gcd_diGui(int a,int b){
    return b==0?a:gcd_diGui(b,a%b);
}
//Stein二进制算法

int main()
{
    cout<<gcd(1112,695)<<" "<<gcd_diGui(1112,695);

    system("pause");
    return 0;
}