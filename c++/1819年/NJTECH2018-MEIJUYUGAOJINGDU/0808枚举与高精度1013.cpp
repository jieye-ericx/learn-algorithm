#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        int x,y,cnt=0;
        for(int i=-9999;i<10000;i++)
            if(i*(n-i)==m){printf("Yes\n");cnt++;break;}
        if(cnt==0)printf("No\n");
    }
    return 0;
}
