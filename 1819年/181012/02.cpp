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
#define N 20002
int prime[N],p_cnt;

int m,a,b,i,j,p,q;

int main(){
    cin>>m>>a>>b;
    for(p=0;p<p_cnt;p++){
        for(q=p;q<p_cnt;q++){
            if(prime[p]*prime[q]<=m && a*prime[q]<=b*prime[p])
        }
    }    
}