#include<stdio.h>
#include<string.h>
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
using namespace std;
int s[10000];//开的稍微大一点，因为不知道循环多少次才会重复
int gm(int m){
    int sum=0,t=0;
    while(1){
        sum+=(m%10)*(m%10);
        m=m/10;
        if(m==0){
            if(sum==1)
                return 1;
            m=sum;
            for(int i=0;i<t;i++){
                if(sum==s[i])
                return 0;
            }
            s[t++]=sum;
            sum=0;  //每次结束都要清0
        }
    }
}
int main(){
    int n;
    while(scanf("%d",&n)&&n!=-1){
        if(gm(n))
        printf("true\n");
        else
        printf("false\n");
    }
    return 0;
}
