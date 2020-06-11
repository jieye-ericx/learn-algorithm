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
int t,a[11],i,m,cnt1,cur1;
char b[11];
int cur;

void dfs(int cur,int le,int ri,int cnt,int now){
    int i,j,flag=0;
    if(cur>=m){
        cur1=cur;
        return ;
    }
    for(i=1;i<=10;i++){
        if(!a[i]) continue;
        if(i==now){
            flag++;
            continue;
        }
        if(cnt&1) {
            //奇数右边放
            if(ri+i>le){
                dfs(cur+1,le,ri+i,cnt+1,i);
                if(cur1>=m) return;
            }else{
                flag++;
            }
        }else{
            if(le+i>ri){
                dfs(cur+1,le+i,ri,cnt+1,i);
                if(cur1>=m) return;
            }else{
                flag++;
            }
        }
    }
    //if(flag==cnt1){
    //    return;
    //}
}

int main(){
    scanf("%d",&t);
    a[0]=0;
    while(t--){
        
        cnt1=0;
        cur1=0;
        //flag2=0;
        scanf("%s",b+1);
        //cin>>b+1;
        for(i=1;i<=10;i++){
            a[i]=b[i]-'0';
            if(a[i]) cnt1++;
            
        }
        scanf("%d",&m);

        dfs(0,0,0,0,0);
        if(cur1>1) printf("YES\n");
        else printf("NO\n");
        

    }
    system("pause");
    return 0;
}